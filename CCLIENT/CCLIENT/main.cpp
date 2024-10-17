#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#include <crtdbg.h>
#include "Client.h"
#include "Board.h"
#include "TColor.h"
#include "Player.h"
#include "Timer.h"
#pragma comment(lib, "ws2_32")

int main()
{
	//Client client;
	shared_ptr<Board> board(new Board());
	Render render(board);
	thread renderThread(&Render::PrintBoard, &render);
	Player player;
	Timer::GetInstance();
	while (true)
	{
		Timer::GetInstance()->Update();
		board->PaintBox(200, 400, 800, 600);
		player.PlayerUpdate();
		player.PrintPlayer(*board);
		render.Trigger();
		board->BufferSwap();
	}
	renderThread.join();

	_CrtDumpMemoryLeaks();
	return 0;
}