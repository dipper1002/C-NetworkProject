#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include "stdafx.h"
#include <iostream>
#include <WinSock2.h>
#include <time.h>

#pragma comment(lib, "ws2_32")
#pragma once
#define PORT 4578
#define PACKET_SIZE 1024

class Server;

using namespace std;

int main()
{
	Server s();

	while (1)
	{
		Sleep(1000);
	}

	return 0;
}