#pragma once
#define CC_SAFE_DELETE(p) do { delete (p); (p) = nullptr; } while(0)
#include"Iterator.h"
//struct DouNode
//{
//	int a;
//	DouNode* pfront;
//	DouNode* pnext;
//};
class Iteraotr;
class MyDouList
{
public:
	typedef Iterator iterator;
	MyDouList();
	~MyDouList();
	DouNode* begin()
	{
		return m_head;
	}
	DouNode* end()
	{
		return m_tail;
	}
	int  getsize()
	{
		return m_size;
	}
	MyDouList(int *list, int num); //list为数组，num为元素个数
	void PrintList();
	void Insert(int value, int pos);
	void Deletebypos(int pos);
	void Deletebyvalue(int value);
	void DouListSort();
private:
	DouNode* m_head;//头结点
	DouNode* m_tail; //尾节点
	int m_size;
};

