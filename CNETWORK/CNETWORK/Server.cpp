#include <iostream>
#include <WinSock2.h>
#include <thread>
#pragma comment(lib, "ws2_32")
#pragma once
using namespace std;

class Server
{
private:
	WSADATA wsaData;
	SOCKET hListen;
	SOCKADDR_IN tListenAddr;
	SOCKADDR_IN tClntAddr;
	int iClntSize;
	SOCKET hClient;
	char cBuffer[1024] = {};
	thread t1;

public:
	Server()
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
		listen(hListen, SOMAXCONN);

		iClntSize = sizeof(tClntAddr);
		hClient = accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize);


		t1 = thread(&Server::GetUpdate,this);
	}
	void GetUpdate()
	{
		while (1)
		{
			recv(hClient, cBuffer, 1024, 0);
			cout << "Receive Message: " << cBuffer << endl;

			char cMsg[] = "Hello, Client!";
			send(hClient, cMsg, strlen(cMsg), 0);
		}
	}


	~Server()
	{
		t1.join();
		closesocket(hClient);
		closesocket(hListen);

		WSACleanup();
	}

};
