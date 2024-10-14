#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#include "Client.h"
#include "Board.h"
#include "TColor.h"
#include "Player.h"
#pragma comment(lib, "ws2_32")

int main()
{
	//Client client;
	Board board;
	Render render;
	Player player;
	while (true)
	{
		//system("cls");
		board.PaintCircle(400, 400, 250, GREEN);
		board.PaintCircle(600, 300, 210, RED);
		board.PaintBox(100, 100, 200, 200, BLUE);
		player.PrintPlayer(board);
		board.PrintBoard(render);
	}
	return 0;
}