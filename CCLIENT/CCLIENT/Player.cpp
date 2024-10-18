#include "Player.h"
#include "TColor.h"
#include "Timer.h"
Player::Player() : 
leftMove(std::make_shared<Observer>([this]() {x -= 150 * Timer::GetInstance()->GetDeltaTime(); })),
rightMove(std::make_shared<Observer>([this]() {x += 150 * Timer::GetInstance()->GetDeltaTime(); })),
upMove(std::make_shared<Observer>([this]() {if (jumpCount > 0) { gravity = -600; jumpCount--; } })),
downMove(std::make_shared<Observer>([this]() { }))
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
	int tempY = y;
	gravity += 800 * Timer::GetInstance()->GetDeltaTime();
	y += gravity * Timer::GetInstance()->GetDeltaTime();

	//임시 바닥 처리
	if ((x > 200 && x < 800) && tempY <= 400 && y > 400 - 25)
	{
		jumpCount = 1;
		y = 400 - 25;
		gravity = 0;
	}
	if (y > 1000)
	{
				y = 300;
		x = 300;
		gravity = 0;
		jumpCount = 1;
	}
}
void Player::PrintPlayer(Board& b)
{
	b.PaintCircle(x, y, 25, 1);
}
