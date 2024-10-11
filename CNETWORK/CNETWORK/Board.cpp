#pragma once
#include <iostream>
#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = ' ';
		}
	}
}
Board::~Board()
{
}
void Board::PrintBoard()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}