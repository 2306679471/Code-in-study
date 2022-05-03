#include"List.h"
#include<iostream>
using namespace std;
List::List()
{
	pHead = new DouNode;
	pRear = new DouNode;
	pHead->pnext = pRear;
	pRear->pfront = pHead;
}
List::~List()
{

}
void List::push_back(const int &val)
{   
	DouNode* pnew = new DouNode;
	pnew->a = val;
	if (pHead->pnext == pRear&&	pRear->pfront == pHead)
	{
		pHead->pnext = pnew;
		pRear->pfront = pnew;
		pnew->pnext = pRear;
		pnew->pfront = pHead;
	}
	else
	{
		pnew->pfront = pRear->pfront;
		pnew->pnext = pRear;
		pRear->pfront->pnext = pnew;
		pRear->pfront = pnew;
	}
	
}
void List::pop_front()
{
	if (pHead->pnext == pRear&&	pRear->pfront == pHead)
	{
		return;
	}
	else
	{
		DouNode* pdel = pHead->pnext;
		pHead->pnext = pdel->pnext;
		pdel->pnext->pfront = pHead;
		pdel->pfront = pdel->pnext = nullptr;
		CC_SAFE_DELETE(pdel);
	}
}
void List::print()
{
	if (pHead->pnext == pRear&&	pRear->pfront == pHead)
	{
		cout << "链表中没有数据" << endl;
		return;
	}
	DouNode* ptemp = pHead->pnext;
	while (ptemp != pRear)
	{
		cout << ptemp->a << endl;
		ptemp = ptemp->pnext;
	}
}
bool List::empty() const
{
	if (pHead->pnext == pRear&&	pRear->pfront == pHead)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void List::clear()
{
	if (empty())
	{
		return;
	}
	else
	{
		DouNode* pdel = pHead->pnext;
		while (pdel= pRear)
		{
			pHead->pnext = pdel->pnext;
			pdel->pnext->pfront = pHead;
			pdel->pfront = pdel->pnext = nullptr;
			CC_SAFE_DELETE(pdel);
			pdel = pHead->pnext;
		}
	}
}
void List::remove(const int& val)
{
	if (pHead->pnext == pRear&&pRear->pfront == pHead)
	{
		return;
	}
	else
	{
		DouNode* pdel = pHead->pnext;
		while (pdel= pRear)
		{
			if (val != pdel->a)
			{
				pdel = pdel->pnext;
			}
			else
			{
				DouNode* ptemp = pdel->pfront;
				ptemp->pnext = pdel->pnext;
				pdel->pnext->pfront = ptemp;
				pdel->pfront = pdel->pnext = nullptr;
				CC_SAFE_DELETE(pdel);
				break;
			}
		}
	}
}
void List::unique()
{
	if (pHead->pnext == pRear&&pRear->pfront == pHead)
	{
		return;
	}
	else if (pHead->pnext->pnext == pRear)
	{
		return;
	}else
	{
		DouNode* cur = pHead->pnext;
		DouNode* ptemp = cur->pnext;
		while (cur != pRear)
		{
			while (ptemp!= pRear)
			{
				if (cur->a != ptemp->a)
				{
					ptemp = ptemp->pnext;
				}
				else
				{
					DouNode* p = ptemp;
					ptemp = ptemp->pnext;
					p->pfront->pnext = ptemp;
					ptemp->pfront = p->pfront;
					p->pfront = p->pnext = nullptr;
					CC_SAFE_DELETE(p);
				}
			}
			cur = cur->pnext;
		}
	}
}
void List::swap(List &lst)
{
	List plist = lst;//临时节点
	lst.pHead = this->pHead;
	lst.pRear = this->pRear;
	this->pHead = plist.pHead;
	this->pRear = plist.pRear;
}
void List::reverse()
{
	DouNode* pr = pRear->pfront;
	DouNode* ph = pHead->pnext;
	if (pHead->pnext->pnext == pRear)
	{
		return;
	}
	else if (3==this->size()||2==this->size())
	{
		int temp = pr->a;
		pr->a = ph->a;
		ph->a = temp;
	}
	else
	{
		if (this->size() % 2 != 0)
		{
			while (( ph -> pnext -> pnext != pr) && (pr -> pfront -> pfront != ph ))
			{
				int temp = pr->a;
				pr->a = ph->a;
				ph->a = temp;
				ph = ph->pnext;
				pr = pr->pfront;
			}
		}
		else
		{
			while ((ph -> pnext != pr) && (pr -> pfront != ph))
			{
				int temp = pr->a;
				pr->a = ph->a;
				ph->a = temp;
				ph = ph->pnext;
				pr = pr->pfront;
			}
		}
	}
}
void List::merge(List &lst)
{
	if (this->isOrder() && lst.isOrder())
	{
		this->pRear->pfront->pnext = lst.pHead->pnext;
		lst.pHead->pnext->pfront = this->pRear->pfront;
		DouNode* p1 = this->pRear;
		DouNode* p2 = lst.pHead;
		CC_SAFE_DELETE(p1);
		CC_SAFE_DELETE(p2);
		this->pRear = lst.pRear;
	}
	else
	{
		this->sort();
		lst.sort();
		merge(lst);
		return;
	}
	
}
void List::sort()//冒泡排序
{
	DouNode* curMax = nullptr;
	DouNode* ptemp = pHead;
	if ((pHead == pRear) || nullptr == pHead)
	{
		return;
	}
	while (ptemp->pnext != curMax)
	{
		if (pHead->a > ptemp->pnext->a)
		{
			pHead = pHead->pnext;
			pHead->pfront = nullptr;
			ptemp->pnext = pHead->pnext;
			pHead->pnext = ptemp;
			ptemp->pfront = pHead;
		}
		else
		{
			ptemp = pHead->pnext;
		}
		while (ptemp->pnext != curMax)
		{
			DouNode* p = ptemp->pnext;
			if (ptemp->a > ptemp->pnext->a)
			{
				if (p == pRear)
				{
					ptemp->pfront->pnext = p;
					p->pfront = ptemp->pfront;
					ptemp->pfront = p;
					ptemp->pnext = nullptr;
					p->pnext = ptemp;
					pRear = ptemp;
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
		ptemp = pHead;
	}
}
int List::size()
{
	int count = 0;
	DouNode* ptemp = pHead->pnext;
	while (ptemp != pRear)
	{
		count++;
	}
	return count;
}
int List::at(int pos)//元素位置从0开始
{
	int mpos=0;
	if (pos > this->size())
	{
		return;
	}
	else
	{
		DouNode* ptemp = pHead->pnext;
		while (ptemp!=pRear)
		{
			if (pos == mpos)
			{
				break;
			}
			++mpos;
			ptemp = ptemp->pnext;
		}
		return ptemp->a;
	}
}
Iterator List::begin()
{
	List::iterator it = Iterator(pHead);
	return it;
}
Iterator List::end()
{
	List::iterator it = Iterator(pRear);
	return it;
}
Iterator List::erase(Iterator pos)
{
	List::iterator it = Iterator(pHead);
	for (; ; it++)
	{
		if (pos == it)
		{
			DouNode* pdel = it.getnode();
			pdel->pfront->pnext = pdel->pnext;
			pdel->pnext->pfront = pdel->pfront;
			pdel->pfront = pdel->pnext = nullptr;
			CC_SAFE_DELETE(pdel);
			break;
		}			
	}
	it++;
	return it;
}
Iterator List::erase(Iterator start, Iterator end)
{
	List::iterator it = Iterator(pHead);
	for (;; it++)
	{
		if (start == it)
		{
			while (it != end++)
			{
				
				DouNode* pdel = it.getnode();
				it++;
				pdel->pfront->pnext = pdel->pnext;
				pdel->pnext->pfront = pdel->pfront;
				pdel->pfront = pdel->pnext = nullptr;
				CC_SAFE_DELETE(pdel);
			}
			break;
		}
	}
	return it;
}
Iterator List::insert(Iterator pos, const int &val)
{
	DouNode* pnew = new DouNode;
	pnew->a = val;
	if ( pHead -> pnext == pRear && pRear -> pfront == pHead)
	{
		pHead->pnext = pnew;
		pRear->pfront = pnew;
		pnew->pnext = pRear;
		pnew->pfront = pHead;
		List::iterator it = Iterator(pHead);
		return it;
	}
	else
	{
		List::iterator it = Iterator(pHead);
		for (; it != pos; it++);
		DouNode* ptemp = it.getnode();
		pnew->pnext = ptemp;
		pnew->pfront = ptemp->pfront;
		ptemp->pfront->pnext = pnew;
		ptemp->pfront = pnew;
		return it;
	}
}
void List::splice(Iterator pos, List &lst)
{
	if (this->isOrder() && lst.isOrder())
	{
		List::iterator it = Iterator(pHead);
		List::iterator it_list = Iterator(lst.pHead);
		for (; it != pos; it++);
		while (it_list != lst.end())
		{
			it = this->insert(it, *it_list);
			it_list++;
		}
		lst.clear();
	}
	else
	{
		this->sort();
		lst.sort();
		splice(pos, lst);
		return;
	}
	
}
bool List::isOrder()
{
	DouNode* ptemp = pHead->pnext;
	while (ptemp != pRear)
	{
		if (ptemp->a <= ptemp->pnext->a)
		{
			ptemp = ptemp->pnext;
			continue;
		}
		else
		{
			return false;
		}
		return true;
	}
}
