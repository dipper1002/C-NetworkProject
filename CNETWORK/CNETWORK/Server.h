#include <iostream>
#include <WinSock2.h>
#include <thread>
#include <vector>
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
	vector<SOCKET> hClient;
	char cBuffer[1024] = {};
	vector<thread> threadList;
	vector<string> messageList;
	thread tSendMessage;
public:
	Server();
	~Server();
	void TSendMessage();
	void TGetUpdate(SOCKET hClient, int id);
	void TGetNewClient();
};

