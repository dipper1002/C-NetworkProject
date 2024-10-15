#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#include "Client.h"
#include "Board.h"
#include "TColor.h"
#include "Player.h"
#include "Timer.h"
#pragma comment(lib, "ws2_32")

int main()
{
	//Client client;
	Board board;
	Render render;
	Player player;
	Timer::GetInstance();
	while (true)
	{
		Timer::GetInstance()->Update();
		//system("cls");
		board.PaintBox(200, 400, 800, 600);
		player.PlayerUpdate();
		player.PrintPlayer(board);
		board.PrintBoard(render);
	}
	return 0;
}