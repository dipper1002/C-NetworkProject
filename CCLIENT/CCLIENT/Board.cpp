#pragma once
#include <iostream>
#include "Board.h"
#include "Map.h"
Board::Board()
{
	board.resize(MAP_SIZE_Y);
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		board[i].resize(MAP_SIZE_X);
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			board[i][j] = 0;
		}
	}
}
Board::~Board()
{
}
void Board::PaintCircle(int x, int y, int r, int color)
{
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			if ((i - y) * (i - y) + (j - x) * (j - x) <= r * r)
			{
				board[i][j] = color+1;
			}
		}
	}
}
void Board::PaintBox(int x1, int y1, int x2, int y2, int color)
{

	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			if (i >= 0 && i < MAP_SIZE_Y && j >= 0 && j < MAP_SIZE_X)
			board[i][j] = color+1;
		}
	}

}
void Board::PrintBoard(Render render)
{
	/*
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}*/
	render.PrintBoard(board);
}