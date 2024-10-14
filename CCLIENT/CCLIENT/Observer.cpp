#pragma once
#include "Observer.h"

Observer::Observer()
{
	fptr = nullptr;
}
Observer::Observer(std::function<void()> fptr)
{
	this->fptr = fptr;
}
Observer::~Observer()
{
}
void Observer::Update()
{
	if (fptr != nullptr)
	fptr();
}
