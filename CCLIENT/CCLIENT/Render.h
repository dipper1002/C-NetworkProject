#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include "Board.h"
#include "RenderObject.h"
#include "DefineSetting.h"

class Board;

using namespace std;

class Render
{
public:
	Render(Board& board_);
	~Render();
	void PrintBoard();
private:
	vector<vector<RenderObject>> board;
	shared_ptr<Board> boardData;
};
