#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "DefineSetting.h"
#include "Render.h"

using namespace std;
class Board
{
public:
	Board();
	~Board();
	void PaintBox(int x1,int y1,int x2,int y2);
	void PrintBoard(Render render);
private:
	vector<vector<bool>> board;
};