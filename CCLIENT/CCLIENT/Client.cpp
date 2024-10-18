#pragma once
#include "Client.h"
#include "DefineSetting.h"
#include <string>
#include <iostream>

using namespace std;

BOOL GetIPAddr(const char* name, IN_ADDR* addr)
{
	HOSTENT* ptr = gethostbyname(name);
	if (ptr == NULL)
	{
		return FALSE;
	}

	memcpy(addr, ptr->h_addr, ptr->h_length);
	return TRUE;
}

Client::Client(Player* player, OtherPlayer* otherPlayer)
{
	this->player = player;
	this->otherPlayer = otherPlayer;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	IN_ADDR addr;
	GetIPAddr(SERVER_IP, &addr);
	tAddr.sin_addr = addr;
	//tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	thread = std::thread(&Client::Update, this);
	recvThread = std::thread(&Client::RecvUpdate, this);
}
//프로토콜 Type(1byte) X(4byte) Y(4byte)
// type = 0 : 내 위치 전송
void Client::Update()
{
	while (1)
	{
		Sleep(100);
		unsigned char x[5] = { 0, };
		unsigned char y[5] = { 0, };
		IntByte::IntToByte(player->GetX(), x);
		IntByte::IntToByte(player->GetY(), y);

		char str[10] = { 0, };
		str[0] = 0;
		for (int i = 0; i < 4; i++)
		{
			str[i + 1] = x[i];
		}
		for (int i = 0; i < 4; i++)
		{
			str[i + 5] = y[i];
		}
		str[9] = '\0';

		send(hSocket, str, sizeof(str), 0);
		//printf("Recv Msg : %s\n", cBuffer);

	}
}
//type = 0 상대방 위치 송신
void Client::RecvUpdate()
{
	while (1)
	{
		recv(hSocket, cBuffer, sizeof(cBuffer), 0);
		int type = cBuffer[0];

		if (type == 0)
		{
			int id = cBuffer[1];
			unsigned int x = 0;
			unsigned int y = 0;
			IntByte::ByteToInt((unsigned char*)&cBuffer[2], x);
			IntByte::ByteToInt((unsigned char*)&cBuffer[6], y);

			//cout << "Recv Msg : " << id << " " << x << " " << y << endl;

			otherPlayer->UpdatePlayer(id, x, y);
		}
	}
}
Client::~Client()
{
	closesocket(hSocket);

	WSACleanup();
}