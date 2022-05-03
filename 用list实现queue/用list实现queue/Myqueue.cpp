#include"Myqueue.h"
using namespace std;
Myqueue::Myqueue(int val)
{
	list.push_front(val);
}
Myqueue::~Myqueue()
{
	list.clear();
}
int& Myqueue::back()
{
	return list.back();
}
bool Myqueue::empty()
{
	if (list.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int& Myqueue::front()
{
	return list.front();
}
void Myqueue::pop()
{
	list.pop_front();
}
void Myqueue::push(const int &val)
{
	list.push_back(val);
}
int Myqueue::size()
{
	return list.size();
}