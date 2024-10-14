#pragma once
#include <vector>
#include <iostream>
#include "RenderObject.h"
#include "DefineSetting.h"

using namespace std;
class Render
{
public:
	Render();
	~Render();
	void PrintBoard(vector<vector<int>>& v);
private:
	vector<vector<RenderObject>> board;
};
