#include "Player.h"
Player::Player() : 
leftMove(std::make_shared<Observer>([this]() {x -= 5; })),
rightMove(std::make_shared<Observer>([this]() {x += 5; })),
upMove(std::make_shared<Observer>([this]() {y -= 5; })),
downMove(std::make_shared<Observer>([this]() {y += 5; }))
{
	x = 300;
	y = 300;
	InputManager::GetInstance()->Subscribe(VK_LEFT, leftMove);
	InputManager::GetInstance()->Subscribe(VK_RIGHT, rightMove);
	InputManager::GetInstance()->Subscribe(VK_UP, upMove);
	InputManager::GetInstance()->Subscribe(VK_DOWN, downMove);
	
}
Player::~Player()
{
}
void Player::PrintPlayer(Board& b)
{
	b.PaintBox(x, y, x+50, y+50,15);
}