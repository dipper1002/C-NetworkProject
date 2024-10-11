#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>
#include <thread>
class Client
{
private:
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN tAddr;
	char cBuffer[1024];
	std::thread* pThread;
	
public:
	Client();
	~Client();
	void Update();

};