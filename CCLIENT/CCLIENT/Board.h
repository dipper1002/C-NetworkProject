#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <mutex>
#include "DefineSetting.h"
#include "Render.h"

class Render;

using namespace std;
class Board
{
public:
	Board();
	~Board();
	void PaintCircle(int x, int y, int r, int color = 15);
	void PaintBox(int x1,int y1,int x2,int y2, int color = 15);
	void PrintBoard(Render render);
	vector<vector<int>> GetBoard();
	void LockMutex();
private:
	vector<vector<int>> board;
	mutex mtx;  
};