#include"Iterator.h"
#include<iostream>
using namespace std;
Iterator Iterator::operator++(int)
{
	node = node->pnext;
	return *this;
}
int Iterator::operator*() const
{
	return node->a;
}
void Iterator::operator++()
{
	node = node->pnext;
}
Iterator Iterator::operator + (int n)
{
	DouNode* p = node;
	while (--n)
	{
		p = p->pnext;
	}
	Iterator it(p);
	return it;
}
DouNode Iterator::operator[](int n)
{
	DouNode* p = node;
	while (--n)
	{
		p = p->pnext;
	}
	return *p;
}
Iterator Iterator::operator = (DouNode* phead)
{
	DouNode* p = phead;
	return Iterator(p);
}
Iterator Iterator::operator=(Iterator t)
{
	this->node = t.node;
	return *this;
}
bool Iterator::operator!=(Iterator& t)
{
	if (this->node != t.node)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Iterator::print(DouNode* end)
{
	DouNode* p = node;
	while (end != p)
	{
		cout << p->a << endl;
		p = p->pnext;
	}
}