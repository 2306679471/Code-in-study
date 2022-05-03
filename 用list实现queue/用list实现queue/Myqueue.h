#pragma once
#include<list>
class Myqueue
{
public:
	int &back();
	bool empty();
	int &front();
	void pop();
	void push(const int &val);
	int size();
	Myqueue(){}
	Myqueue(int val);
	~Myqueue();
private:
	std::list<int> list;
};