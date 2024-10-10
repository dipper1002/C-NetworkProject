#include "Server.h"
#pragma comment(lib, "ws2_32")
#pragma once
using namespace std;

Server::Server()
{
	cout << "Server is running..." << endl;
	WSAStartup(MAKEWORD(2, 2), &this->wsaData);

	//소켓 구축
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	//주소정보 초기화
	tListenAddr = {};
	tListenAddr.sin_family = AF_INET;
	tListenAddr.sin_port = htons(4578);
	tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));


	threadList.push_back(thread(&Server::TGetNewClient, this));
}
Server::~Server()
{
	for (int i=0;i< threadList.size();i++)
	{
		threadList[i].join();
	}
	for (auto hClient : hClient)
	{
		closesocket(hClient);
	}
	closesocket(hListen);

	WSACleanup();
}
void Server::TGetUpdate(SOCKET hClient)
{
	while (1)
	{
		int output = recv(hClient, cBuffer, 1024, 0);
		if (output == 0)
		{
			cout << "Client Disconnected" << endl;
			break;
		}
		cout << "Receive Message: " << cBuffer << endl;

		char cMsg[] = "Hello, Client!";
		send(hClient, cMsg, strlen(cMsg), 0);
	}
}
void Server::TGetNewClient()
{
	while (1)
	{
		listen(hListen, SOMAXCONN);

		iClntSize = sizeof(tClntAddr);
		hClient.push_back(accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize));
		threadList.push_back(thread(&Server::TGetUpdate, this, hClient[hClient.size()-1]));
	}
}