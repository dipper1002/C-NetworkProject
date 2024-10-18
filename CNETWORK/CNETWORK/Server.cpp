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
	tSendMessage = thread(&Server::TSendMessage, this);
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
void Server::TGetUpdate(SOCKET hClient, int id)
{
	while (1)
	{
		int output = recv(hClient, cBuffer, 1024, 0);
		cBuffer[output] = '\0';

		string strBuffer = "";
		for (int i = 1; i < output; i++)
		{
			strBuffer += cBuffer[i];
		}


		if (output <= 0)
		{
			cout << "Client Disconnected" << endl;
			break;
		}
		messageList[id] = strBuffer;
		//cout << "Receive Message: " <<"ID:" <<id<<" " << strBuffer << endl;

		//char cMsg[] = "Hello, Client!";
		//send(hClient, cMsg, strlen(cMsg), 0);
	}
}
void Server::TGetNewClient()
{
	while (1)
	{
		listen(hListen, SOMAXCONN);

		iClntSize = sizeof(tClntAddr);
		messageList.push_back("");
		hClient.push_back(accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize));
		threadList.push_back(thread(&Server::TGetUpdate, this, hClient[hClient.size()-1], hClient.size()-1));
	}
}
void ByteToInt(unsigned char* bytes, unsigned int& n)
{
	n = (bytes[0] & 0xFF) << 24 | (bytes[1] & 0xFF) << 16 | (bytes[2] & 0xFF) << 8 | (bytes[3] & 0xFF);
}
void Server::TSendMessage()
{
	while (1)
	{
		Sleep(100);
		string strBuffer;
		for (int i = 0; i < hClient.size(); i++)
		{
			int id = 0;
			for (int j = 0; j < hClient.size(); j++)
			{
				if (messageList[j] == "")continue;
				if (i == j)continue;

				strBuffer = char(0);
				strBuffer += char(id++);

				strBuffer += messageList[j];
				send(hClient[i], strBuffer.c_str(), strBuffer.size(), 0);
			}
			unsigned int x, y;
			ByteToInt((unsigned char*)messageList[i].c_str(), x);
			ByteToInt((unsigned char*)messageList[i].c_str() + 4, y);
			cout << "User Pos : X: " << x << " Y: " << y << endl;
		}
		cout << "User Count: " << hClient.size() << endl;
	}
}