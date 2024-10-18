#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>
#include <thread>
#include "OtherPlayer.h"
#include "Player.h"
#include "IntByte.h"
class Client
{
private:
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN tAddr;
	char cBuffer[1024];
	std::thread thread;
	std::thread recvThread;
	Player* player;
	OtherPlayer* otherPlayer;
	
public:
	Client(Player* player, OtherPlayer* otherPlayer);
	~Client();
	void Update();
	void RecvUpdate();

};