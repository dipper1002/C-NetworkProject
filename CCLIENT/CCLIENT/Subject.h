#pragma once
#include "Observer.h";
#include <vector>
#include <memory>

using namespace std;

class Subject
{
public:
	Subject();
	~Subject();
	void Subscribe(std::shared_ptr<Observer> obs);
	void Notify();

private:
	vector<std::shared_ptr<Observer>> observers;
};