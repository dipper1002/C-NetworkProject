#pragma once
#include "Client.h"
#include "DefineSetting.h"
#include <string>
#include <iostream>
using namespace std;
Client::Client()
{
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	Update();
}
void Client::Update()
{
	while (1)
	{
		string str;
		cin >> str;
		if (str == "exit")
		{
			break;
		}
		send(hSocket, str.c_str(), str.size(), 0);

		recv(hSocket, cBuffer, PACKET_SIZE, 0);
		printf("Recv Msg : %s\n", cBuffer);

	}
}
Client::~Client()
{
	closesocket(hSocket);

	WSACleanup();
}