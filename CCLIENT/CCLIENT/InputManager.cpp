#pragma once
#include "InputManager.h"
#include <Windows.h>
#include <time.h>

InputManager* InputManager::instance = nullptr;

InputManager* InputManager::GetInstance()
{
	if (instance == nullptr)
		instance = new InputManager();
	return instance;
}
InputManager::InputManager()
{
	inputThread = std::thread(&InputManager::Update, this);
}
InputManager::~InputManager()
{
	inputThread.join();
}
void InputManager::Subscribe(int key, shared_ptr<Observer> obs)
{
	if (keys.find(key) == keys.end())
	{
		keys[key] = Subject();
	}
	keys[key].Subscribe(obs);
}
void InputManager::Notify(int key)
{
	keys[key].Notify();
}
void InputManager::Update()
{
	while (true)
	{
		Sleep(1);
		for (auto& key : keys)
		{
			if (GetAsyncKeyState(key.first))
			{
				Notify(key.first);
			}
		}
	}
}