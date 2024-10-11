#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#include "Client.h"
#include "Board.h"
#pragma comment(lib, "ws2_32")

int main()
{
	//Client client;
	Board board;
	Render render;
	board.PaintBox(100, 100, 400, 400);
	board.PaintBox(300, 300, 500, 500);
	board.PrintBoard(render);
	return 0;
}