#pragma once
#include <iostream>
#include "Board.h"
#include "Map.h"
#include <thread>
Board::Board()
{
	board.resize(2);
	for (int k = 0; k < 2; k++)
	{
		board[k].resize(MAP_SIZE_Y);
		for (int i = 0; i < MAP_SIZE_Y; i++)
		{
			board[k][i].resize(MAP_SIZE_X);
			for (int j = 0; j < MAP_SIZE_X; j++)
			{
				board[k][i][j] = 0;
			}
		}
	}
}
Board::~Board()
{
}
void Board::BufferInit()
{
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			board[doubleBuff][i][j] = 0;
		}
	}
}
void Board::BufferSwap()
{
	doubleBuff = !doubleBuff;
}
void Board::PaintCircle(int x, int y, int r, int color)
{
	LockMutex();

	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			if ((i - y) * (i - y) + (j - x) * (j - x) <= r * r)
			{
				board[doubleBuff][i][j] = color+1;
			}
		}
	}
	UnLockMutex();
}
void Board::ClearBoard()
{
	LockMutex();
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			board[doubleBuff][i][j] = 0;
		}
	}
	UnLockMutex();
}
void Board::PaintBox(int x1, int y1, int x2, int y2, int color)
{
	LockMutex();
	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			if (i >= 0 && i < MAP_SIZE_Y && j >= 0 && j < MAP_SIZE_X)
			board[doubleBuff][i][j] = color+1;
		}
	}
	UnLockMutex();

}
void Board::PrintBoard(Render& render)
{
	thread t1(&Render::PrintBoard, &render);
	t1.join();
}
void Board::LockMutex()
{
	mtx.lock();
}
void Board::UnLockMutex()
{
	mtx.unlock();

}
vector<vector<int>> Board::GetBoard()
{
	unique_lock<mutex> lock(mtx);
	return board[!doubleBuff];
}