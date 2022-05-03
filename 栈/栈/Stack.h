#pragma once
#include<list>
using namespace std;
//struct Stack
//{
//	int m_a;
//	Stack* m_top;
//	Stack(int a) :m_a(a), m_top(nullptr) {}
//
//};
class Stack
{
	Stack();
	bool empty();
	void push(const int &val);
	void pop();
	int size();
	~Stack();
	int& top();
private:
	list<int> list;
};