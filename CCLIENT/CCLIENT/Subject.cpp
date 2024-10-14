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
    // ���������� ��ȸ
    for (int i = observers.size() - 1; i >= 0; i--)
    {
        if (observers[i] != nullptr)
        {
            observers[i]->Update(); // Update ȣ��
        }
        else
        {
            // nullptr�� ��� ����
            observers.erase(observers.begin() + i);
        }
    }
}