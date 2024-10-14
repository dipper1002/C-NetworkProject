#pragma once
#include <functional>

class Observer
{
public:
	Observer();
	Observer(std::function<void()> fptr);
	~Observer();
	void Update();
private:
	std::function<void()> fptr;
};