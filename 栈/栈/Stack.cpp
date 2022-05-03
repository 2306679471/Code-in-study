#include"Stack.h"
bool Stack::empty()
{
	if (list.empty())
		return true;
	else
		return false;
}
void Stack::push(const int &val)
{
	list.push_back(val);
}
void Stack::pop()
{
	list.pop_back();
}
int Stack::size()
{
	return list.size();
}
int& Stack::top()
{
	return list.back();
}