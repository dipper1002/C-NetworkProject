#include "Player.h"
#include "TColor.h"
Player::Player() : 
leftMove(std::make_shared<Observer>([this]() {x -= 5; })),
rightMove(std::make_shared<Observer>([this]() {x += 5; })),
upMove(std::make_shared<Observer>([this]() {if (jumpCount > 0) { gravity = -22; jumpCount--; } })),
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
void Player::PlayerUpdate()
{
	gravity += 2;
	y += gravity;
	if (y > 400 - 25)
	{
		jumpCount = 1;
		y = 400 - 25;
		gravity = 0;
	}
}
void Player::PrintPlayer(Board& b)
{
	b.PaintBox(x-25, y-25, x+25, y+25,RED);
}