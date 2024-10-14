#pragma once
#include "Subject.h"
#include <iostream>
Subject::Subject()
{
}
Subject::~Subject()
{
}
void Subject::Subscribe(std::shared_ptr<Observer> obs)
{
	observers.push_back(obs);
}
void Subject::Notify()
{
    // 역방향으로 순회
    for (int i = observers.size() - 1; i >= 0; i--)
    {
        if (observers[i] != nullptr)
        {
            observers[i]->Update(); // Update 호출
        }
        else
        {
            // nullptr인 경우 삭제
            observers.erase(observers.begin() + i);
        }
    }
}