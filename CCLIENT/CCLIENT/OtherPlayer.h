#pragma once
#include "Board.h"
#include <vector>

using namespace std;

class OtherPlayer
{
public:
	OtherPlayer();
	~OtherPlayer();
	void PrintPlayer(Board& board);
	void AddPlayer(int x, int y);
	void UpdatePlayer(int id,int x, int y);
private:
	vector<pair<int,int>> otherPlayer;

};