#pragma once
#include <unordered_map>
#include <string>
#include <thread>
#include "Subject.h"
class InputManager
{
public:
	static InputManager* GetInstance();
	InputManager();
	~InputManager();
	void Subscribe(int key, shared_ptr<Observer> obs);
	void Notify(int key);
	void Update();
private:
	static InputManager* instance;
	std::unordered_map<int, Subject> keys;
	thread inputThread;
};