#pragma once

#include <thread>
using namespace std;
class Timer
{
public:
	static Timer* GetInstance();
	Timer();
	~Timer();
	void Update();
	double GetDeltaTime();
private:
	static Timer *instance;
	__int64 curTime;
	__int64 lastTime;
	__int64 periodFrequency;
	double deltaTime;
	double timeScale;
	thread t1;
};