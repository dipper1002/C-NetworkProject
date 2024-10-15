#include "Player.h"
#include "TColor.h"
#include "Timer.h"
Player::Player() : 
leftMove(std::make_shared<Observer>([this]() {x -= 50 * Timer::GetInstance()->GetDeltaTime(); })),
rightMove(std::make_shared<Observer>([this]() {x += 50 * Timer::GetInstance()->GetDeltaTime(); })),
upMove(std::make_shared<Observer>([this]() {if (jumpCount > 0) { gravity = -400; jumpCount--; } })),
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
	gravity += 400 * Timer::GetInstance()->GetDeltaTime();
	y += gravity * Timer::GetInstance()->GetDeltaTime();
	if (y > 400 - 25)
	{
		jumpCount = 1;
		y = 400 - 25;
		gravity = 0;
	}
}
void Player::PrintPlayer(Board& b)
{
	b.PaintBox((int)x-25, (int)y-25, x+25, y+25,RED);
}