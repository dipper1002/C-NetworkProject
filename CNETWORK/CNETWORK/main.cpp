#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include "stdafx.h"
#include <iostream>
#include <WinSock2.h>
#include <time.h>
#include "Server.h"

#pragma comment(lib, "ws2_32")
#pragma once
#define PORT 4578
#define PACKET_SIZE 1024

using namespace std;

int main()
{
	shared_ptr<Server> server = make_shared<Server>();
	
	while (1)
	{
		Sleep(1000);
	}

	return 0;
}