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
	Render(shared_ptr<Board> board_);
	~Render();
	void PrintBoard();
	void Trigger();
private:
	vector<vector<RenderObject>> board;
	shared_ptr<Board> boardData;
	bool ready = false;
	mutex mtx;
	condition_variable cv;
};
