#pragma once
#include "RenderObject.h"
#include "DefineSetting.h"
#include "math.h"
#include "TColor.h"
#include <Windows.h>

#include<iostream>

using namespace std;
RenderObject::RenderObject()
{
	this->leftUp = 0;
	this->rightUp = 0;
	this->leftDown = 0;
	this->rightDown = 0;
	this->color = 15;
}	
RenderObject::RenderObject(int leftUp, int rightUp, int leftDown, int rightDown, int color )
{
	table[0][0] = ' ';
	table[0][1] = '\'';
	table[0][2] = ',';
	table[0][3] = '/';
	table[1][0] = '.';
	table[1][1] = '(';
	table[1][2] = '_';
	table[1][3] = 'd';
	table[2][0] = '`';
	table[2][1] = '^';
	table[2][2] = 'l';
	table[2][3] = 'r';
	table[3][0] = 'b';
	table[3][1] = 'B';
	table[3][2] = '\\'; 
	table[3][3] = 'q';

	this->leftUp = leftUp;
	this->rightUp = rightUp;
	this->leftDown = leftDown;
	this->rightDown = rightDown;
	this->color = color;
}
RenderObject::~RenderObject()
{
}
void RenderObject::Print(int x, int y)
{
	int lu = leftUp  / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);
	int ru = rightUp / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);
	int ld = leftDown / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);
	int rd = rightDown / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);

	TextColor(color, BLACK);

	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << table[lu * 2 + rd][ru + ld * 2];
}
void RenderObject::SetColor(int color)
{
	this->color = color;
}
void RenderObject::SetState(int leftUp, int rightUp, int leftDown, int rightDown)
{
	this->leftUp = leftUp;
	this->rightUp = rightUp;
	this->leftDown = leftDown;
	this->rightDown = rightDown;
}