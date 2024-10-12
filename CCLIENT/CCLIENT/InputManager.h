#pragma once
#include <unordered_map>
#include <string>
class InputManager
{
public:
	InputManager();
	~InputManager();
	void Subscribe();
	void Notify();
	void Update();
private:
	//std::unordered_map<std::string, List<>> keys;
};