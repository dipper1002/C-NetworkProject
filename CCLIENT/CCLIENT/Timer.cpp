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
    //1�ʵ��� CPU�� �������� ��ȯ�ϴ� �Լ� (������. �ý��� ���ý� ������)


    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
    // �������Լ��� Update()�Լ����� ������ ����Ǳ� ������ lastTime�� ����.

    timeScale = 1.0 / (double)periodFrequency;
    // �̸�  '1 / �ʴ�������'  �� ���·� ����� ���´�.
    // ��ǻ�ʹ� ���������꺸�� ���������� �� �����⶧���� �� �����Ӹ��� ������ �ؾ��Ұ�� 
    //������ �������� ���� ��궧 �����ϰ� �������°� ����.

}

Timer::~Timer()
{
}

void Timer::Update()
{
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime); // ���� ������ ������ ����.

    deltaTime = (double)(curTime - lastTime) * timeScale; // (���� ������ ������ - ���� ������ ������) * ( 1 / �ʴ������� )

    lastTime = curTime; // ���� �������� ���� ���������� ����. ���� ��� �ݺ�.
}

double Timer::GetDeltaTime() // �ʿ��Ѱ����� ������ ����.
{
    return deltaTime;
}
