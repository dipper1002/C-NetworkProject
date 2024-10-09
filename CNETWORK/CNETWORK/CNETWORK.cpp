#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include "stdafx.h"
#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

#define PORT 4578
#define PACKET_SIZE 1024

using namespace std;

int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hListen;
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tListenAddr = {};
	tListenAddr.sin_family = AF_INET;
	tListenAddr.sin_port = htons(PORT);
	tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
	listen(hListen, SOMAXCONN);

	SOCKADDR_IN tClntAddr = {};
	int iClntSize = sizeof(tClntAddr);
	SOCKET hClient = accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize);

	char cBuffer[PACKET_SIZE] = {};
	recv(hClient, cBuffer, PACKET_SIZE, 0);
	cout << "Receive Message: " << cBuffer << endl;

	char cMsg[] = "Hello, Client!";
	send(hClient, cMsg, strlen(cMsg), 0);

	closesocket(hClient);
	closesocket(hListen);

	WSACleanup();
	return 0;
}