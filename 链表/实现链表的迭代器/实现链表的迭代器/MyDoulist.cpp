#include "MyDouList.h"
#include<iostream>
using namespace std;

MyDouList::MyDouList()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}
MyDouList::~MyDouList()
{
	if (nullptr == m_head)
	{
		return;
	}

	DouNode *p = m_head;
	while (nullptr != m_head)
	{
		m_head = m_head->pnext;
		free(p);
		p = m_head;
	}

	m_size = 0;
	m_tail = nullptr;

}
MyDouList::MyDouList(int * list, int num) : m_head(nullptr), m_tail(nullptr), m_size(0)//创建一个里面存的值为list[num]的链表
{
	if (nullptr == list || 0 == num)
	{
		return;
	}
	for (int i = 0; i < num + 1; i++)
	{
		DouNode* pnew = new DouNode;
		pnew->pfront = nullptr;
		pnew->pnext = nullptr;
		pnew->a = list[i];
		if (nullptr == m_head)
		{
			m_head = pnew;
			m_tail = pnew;
		}
		else
		{
			pnew->pfront = m_tail;
			m_tail->pnext = pnew;
			m_tail = pnew;
		}
		++m_size;
	}
}
void MyDouList::PrintList()//打印链表数据
{
	DouNode* ptemp = m_head;
	for (; ptemp != m_tail; ptemp = ptemp->pnext)
	{
		cout << ptemp->a << endl;
	}
}
void MyDouList::Insert(int value, int pos)//插入数据
{
	DouNode* pnew = new DouNode;
	pnew->pfront = nullptr;
	pnew->pnext = nullptr;
	pnew->a = value;
	DouNode* pre = m_head;
	DouNode* ptemp = pre->pnext;
	int mpos = 1;
	if (nullptr == m_head && nullptr == m_tail)
	{
		m_head = m_tail = pnew;
		++m_size;
	}
	else
	{
		if (pos <= 1)
		{
			m_head->pfront = pnew;
			pnew->pnext = m_head;
			m_head = pnew;
			++m_size;
		}
		else
		{
			DouNode* ptemp = m_head;
			for (; ptemp->pnext != m_tail; ptemp = ptemp->pnext)
			{
				++mpos;
				if (mpos == pos)
				{
					break;
				}
			}
			pnew->pnext = ptemp->pnext;
			pnew->pfront = ptemp;
			ptemp->pnext->pfront = pnew;
			ptemp->pfront = pnew;
			++m_size;
		}
	}
}
void MyDouList::Deletebypos(int pos)//位置删除元素
{
	DouNode* p = nullptr;
	int mpos = 1;
	if ((m_head == m_tail) && nullptr == m_head)
	{
		return;
	}
	else
	{
		if (pos <= 1)
		{
			if (m_head == m_tail)
			{
				p = m_head;
				m_head = m_tail = nullptr;
				CC_SAFE_DELETE(p);
				--m_size;
			}
			else
			{
				p = m_head;
				m_head->pnext->pfront = nullptr;
				m_head = m_head->pnext;
				CC_SAFE_DELETE(p);
				--m_size;
			}
		}
		else
		{
			DouNode* ptemp = m_head;
			for (; ptemp->pnext != m_tail; ptemp = ptemp->pnext)
			{
				++mpos;
				if (mpos == pos)
				{
					break;
				}
			}
			p = ptemp;
			ptemp->pfront->pnext = ptemp->pnext;
			ptemp->pnext->pfront = ptemp->pfront;
			CC_SAFE_DELETE(p);
		}
	}
}
void MyDouList::Deletebyvalue(int value)//删除第一个值为value的节点
{
	DouNode* p = nullptr;//保存要删除的那个节点
	int mpos = 1;
	if ((m_head == m_tail) && nullptr == m_head)
	{
		return;
	}
	else
	{
		if (value == m_head->a)
		{
			if (m_head == m_tail)//当前链表只有一个元素
			{
				p = m_head;
				m_head = m_tail = nullptr;
				CC_SAFE_DELETE(p);
				--m_size;
			}
			else
			{
				p = m_head;
				m_head->pnext->pfront = nullptr;
				m_head = m_head->pnext;
				CC_SAFE_DELETE(p);
				--m_size;
			}
		}
		else
		{
			DouNode* ptemp = m_head;
			for (; ptemp->pnext != nullptr&&ptemp->pnext->a != value; ptemp = ptemp->pnext);
			p = ptemp;
			ptemp->pfront->pnext = ptemp->pnext;
			ptemp->pnext->pfront = ptemp->pfront;
			CC_SAFE_DELETE(p);
		}
	}
}
void MyDouList::DouListSort()//冒泡排序
{
	DouNode* curMax = nullptr;
	DouNode* ptemp = m_head;
	if ((m_head == m_tail) || nullptr == m_head)
	{
		return;
	}
	while (ptemp->pnext != curMax)
	{
		if (m_head->a > ptemp->pnext->a)
		{
			m_head = m_head->pnext;
			m_head->pfront = nullptr;
			ptemp->pnext = m_head->pnext;
			m_head->pnext = ptemp;
			ptemp->pfront = m_head;
		}
		else
		{
			ptemp = m_head->pnext;
		}
		while (ptemp->pnext != curMax)
		{
			DouNode* p = ptemp->pnext;
			if (ptemp->a > ptemp->pnext->a)
			{
				if (p == m_tail)
				{
					ptemp->pfront->pnext = p;
					p->pfront = ptemp->pfront;
					ptemp->pfront = p;
					ptemp->pnext = nullptr;
					p->pnext = ptemp;
					m_tail = ptemp;
				}
				else
				{
					p->pfront = ptemp->pfront;
					ptemp->pfront->pnext = p;
					ptemp->pfront = p;
					ptemp->pnext = p->pnext;
					p->pnext = ptemp;
					p = ptemp->pnext;
					p->pfront = ptemp;
				}
			}
		}
		curMax = ptemp;
		ptemp = m_head;
	}
}