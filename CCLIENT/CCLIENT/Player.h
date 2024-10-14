#pragma once
#include "InputManager.h"
#include "Board.h"
#include <Windows.h>
#include <memory>
class Player
{
public:
	Player();
	~Player();
	void PrintPlayer(Board& b);
	void PlayerUpdate();
private:
	int x, y;
	float gravity;
	int jumpCount;
	shared_ptr<Observer> leftMove;
	shared_ptr<Observer> rightMove;
	shared_ptr<Observer> upMove;
	shared_ptr<Observer> downMove;
};