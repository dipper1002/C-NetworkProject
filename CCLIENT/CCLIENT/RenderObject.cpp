#pragma once
#include "RenderObject.h"
#include "DefineSetting.h"
#include "math.h"
#include<iostream>

using namespace std;
RenderObject::RenderObject()
{
	this->leftUp = 0;
	this->rightUp = 0;
	this->leftDown = 0;
	this->rightDown = 0;
	this->color = 0;
}	
RenderObject::RenderObject(int leftUp, int rightUp, int leftDown, int rightDown, int color )
{
	this->leftUp = leftUp;
	this->rightUp = rightUp;
	this->leftDown = leftDown;
	this->rightDown = rightDown;
	this->color = color;
}
RenderObject::~RenderObject()
{
}
void RenderObject::Print()
{
	int lu = leftUp  / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);
	int ru = rightUp / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);
	int ld = leftDown / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);
	int rd = rightDown / (TILE_SIZE_X * TILE_SIZE_Y / 4 / 1.9);


	if (lu == 0 && ru == 0 && ld == 0 && rd == 0)		cout << " ";
	else if (lu == 0 && ru == 1 && ld == 0 && rd == 0) cout << "'";
	else if (lu == 0 && ru == 0 && ld == 1 && rd == 0) cout << ",";
	else if (lu == 0 && ru == 1 && ld == 1 && rd == 0) cout << "/";
	else if (lu == 0 && ru == 0 && ld == 0 && rd == 1) cout << ".";
	else if (lu == 0 && ru == 1 && ld == 0 && rd == 1) cout << "(";
	else if (lu == 0 && ru == 0 && ld == 1 && rd == 1) cout << "_";
	else if (lu == 0 && ru == 1 && ld == 1 && rd == 1) cout << "d";
	else if (lu == 1 && ru == 0 && ld == 0 && rd == 0) cout << "`";
	else if (lu == 1 && ru == 1 && ld == 0 && rd == 0) cout << "^";
	else if (lu == 1 && ru == 0 && ld == 1 && rd == 0) cout << "l";
	else if (lu == 1 && ru == 1 && ld == 1 && rd == 0) cout << "r";
	else if (lu == 1 && ru == 0 && ld == 1 && rd == 1) cout << "b";
	else if (lu == 1 && ru == 1 && ld == 1 && rd == 1) cout << "B";
	else if (lu == 1 && ru == 0 && ld == 0 && rd == 1) cout << "\\";
	else if (lu == 1 && ru == 1 && ld == 0 && rd == 1) cout << "q";
	
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