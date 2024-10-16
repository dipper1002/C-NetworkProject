#include "Timer.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Timer* Timer::instance = nullptr;

Timer* Timer::GetInstance()
{
    if (instance == nullptr)
    {
		instance = new Timer();
	}
	return instance;
}
Timer::Timer()
{

    QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
    //1초동안 CPU의 진동수를 반환하는 함수 (고정값. 시스템 부팅시 고정됨)


    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
    // 생성자함수는 Update()함수보다 이전에 실행되기 때문에 lastTime에 저장.

    timeScale = 1.0 / (double)periodFrequency;
    // 미리  '1 / 초당진동수'  의 형태로 만들어 놓는다.
    // 컴퓨터는 나눗셈연산보다 곱셈연산이 더 빠르기때문에 매 프레임마다 연산을 해야할경우 
    //역수로 만들어놓고 실제 계산때 곱셈하게 만들어놓는게 좋다.

}

Timer::~Timer()
{
}

void Timer::Update()
{
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime); // 현재 프레임 진동수 저장.

    deltaTime = (double)(curTime - lastTime) * timeScale; // (현재 프레임 진동수 - 이전 프레임 진동수) * ( 1 / 초당진동수 )

    lastTime = curTime; // 현재 프레임을 이전 프레임으로 저장. 이후 계속 반복.
}

double Timer::GetDeltaTime() // 필요한곳에서 가져다 쓰기.
{
    return deltaTime;
}
