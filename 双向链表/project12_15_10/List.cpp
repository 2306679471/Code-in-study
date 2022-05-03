#include "List.h"
#include "Node.h"
#include <assert.h>
#include <iostream>
#include "Iterator.h"
using namespace std;
List::List()
	:pHead(new Node),
	pRear(new Node)
{
	// 创建辅助头和辅助尾,进行连接
	// 1.辅助头的后继是辅助尾
	pHead->pNext = pRear;
	// 2.辅助尾的前驱是辅助头
	pRear->pFront = pHead;
}


List::~List()
{
	// 释放所有结点的内存
	clear();
	// 释放辅助头和辅助尾
	delete pHead;
	pHead = nullptr;
	delete pRear;
	pRear = nullptr;
}

void List::push_back(const int& val)
{
	// 创建新结点pNew,插入在辅助尾的前面
	Node* pNew = new Node(val,pRear->pFront,pRear);
	// 1.新结点的前驱是辅助尾的前驱
	// pNew->pFront = pRear->pFront;
	// 2.新结点的后继是辅助尾
	// pNew->pNext = pRear;
	// 3.辅助尾的前驱的后继是新结点
	pRear->pFront->pNext = pNew;
	// 4.辅助尾的前驱是新结点
	pRear->pFront = pNew;
}

void List::pop_front()
{
	// 断言不能为空
	assert(!empty());// 条件为真,程序继续执行,如果为假,程序中断

	// 1.接收要删除的结点
	Node* pDel = pHead->pNext;
	// 2.辅助头的后继是pDel的后继
	pHead->pNext = pDel->pNext;
	// 3.pDel的后继的前驱是辅助头
	pDel->pNext->pFront = pHead;
	// 4.释放pDel指向的内存
	delete pDel;
	pDel = nullptr;
}

void List::print()
{
	// 遍历
	Node* pNode = pHead->pNext;
	while (pNode != pRear)
	{
		cout << pNode->data << endl;
		pNode = pNode->pNext;
	}
}

bool List::empty() const
{
	return pHead->pNext == pRear;
}

void List::clear()
{
	if (empty())
	{
		return;
	}
	Node* pNode = pHead->pNext;
	while (pNode != pRear)
	{
		// 临时保存下一个
		Node* pTemp = pNode->pNext;
		delete pNode;
		pNode = pTemp;
	}
	// 连接辅助头和辅助尾
	pHead->pNext = pRear;
	pRear->pFront = pHead;
}

void List::remove(const int& val)
{
	if (empty())
	{
		return;
	}
	Node* pNode = pHead->pNext;
	while (pNode != pRear)
	{
		// 判断当前结点的值是否等于val
		if (val == pNode->data)
		{
			// 临时保存下一个结点
			Node* pTemp = pNode->pNext;
			// pNode的前驱的后继是pNode的后继
			pNode->pFront->pNext = pNode->pNext;
			// pNode的后继的前驱是pNode的前驱
			pNode->pNext->pFront = pNode->pFront;
			// 释放pNode指向的内存
			delete pNode;
			pNode = pTemp;
		}
		else
		{
			pNode = pNode->pNext;
		}
	}
}

void List::unique()
{
	if (empty())
	{
		return;
	}
	Node* pNode = pHead->pNext;
	while (pNode != pRear->pFront)
	{
		// 比较相邻两个元素的值
		if (pNode->data == pNode->pNext->data)
		{
			// 临时保存下一个结点
			Node* pDel = pNode->pNext;
			// pNode的后继的后继的前驱是pNode
			pDel->pNext->pFront = pNode;
			// pNode的后继是pNode后继的后继
			pNode->pNext = pDel->pNext;
			// 释放pNode的下一个结点
			delete pDel;
			pDel = nullptr;
		}
		else
		{
			pNode = pNode->pNext;
		}
	}
}

void List::swap(List& lst)
{
	if (empty() && lst.empty())
	{
		return;
	}

	// 交换辅助头
	Node* pTemp = pHead;
	pHead = lst.pHead;
	lst.pHead = pTemp;

	// 交换辅助尾
	pTemp = pRear;
	pRear = lst.pRear;
	lst.pRear = pTemp;
}

void List::reverse()
{
	// 没有结点或者只有一个结点
	/*if (0 == size() || 1 == size())
	{
		return;
	}*/
	// 所有结点交换前驱和后继的指向
	Node* pNode = pHead;
	while (pNode != nullptr)
	{
		Node* pTemp = pNode->pNext;
		pNode->pNext = pNode->pFront;
		pNode->pFront = pTemp;

		pNode = pNode->pFront;// 原本的后继(现在的前驱)
	}
	// 交换辅助头尾的指向
	Node* pTemp = pHead;
	pHead = pRear;
	pRear = pTemp;
}

Iterator List::begin()
{
	// 返回指向真正的第一个结点的迭代器
	return Iterator(pHead->pNext);
}

Iterator List::end()
{
	// 指向真正尾结点的后一个结点的迭代器
	return Iterator(pRear);
}

Iterator List::erase(Iterator pos)
{
	// 1.接收要删除的结点指针
	Node* pDel = pos.pNode;// 对象.数据成员
	// 2.pDel的前驱的后继是pDel的后继
	pDel->pFront->pNext = pDel->pNext;
	// 3.pDel的后继的前驱是pDel的前驱
	pDel->pNext->pFront = pDel->pFront;
	// 4.保存pDel的下一个结点
	Node* pTemp = pDel->pNext;
	// 5.释放内存
	delete pDel;
	pDel = nullptr;
	// 6.返回pTemp的迭代器
	return Iterator(pTemp);
}

Iterator List::erase(Iterator start, Iterator end)
{
	Iterator it = start;
	while (it != end)
	{
		it = erase(it);
	}
	return end;
}

Iterator List::insert(Iterator pos, const int &val)
{
	// 1.接收要插入的位置
	Node* pNode = pos.pNode;
	// 2.创建新结点
	Node* pNew = new Node(val, pNode->pFront, pNode);
	// 3.pNode的前驱的后继是pNew
	pNode->pFront->pNext = pNew;
	// 4.pNode的前驱是pNew
	pNode->pFront = pNew;
	// 5.返回指向新结点的迭代器
	return Iterator(pNew);
}

void List::splice(Iterator pos, List &lst)
{
	if (lst.empty())
	{
		return;
	}

	// 接收要插入的位置
	Node* pNode = pos.pNode;
	lst.pHead->pNext->pFront = pNode->pFront;
	pNode->pFront->pNext = lst.pHead->pNext;
	lst.pRear->pFront->pNext = pNode;
	pNode->pFront = lst.pRear->pFront;

	// lst头尾相连
	lst.pHead->pNext = lst.pRear;
	lst.pRear->pFront = lst.pHead;
}

void List::merge(List &lst)
{
	assert(isOrder() && lst.isOrder());// 两个链表都有序
	// pNode1遍历当前链表
	Node* pNode1 = pHead->pNext;
	// pNode2遍历lst链表
	Node* pNode2 = lst.pHead->pNext;
	// 循环
	while (pNode1 != pRear && pNode2 != lst.pRear)
	{
		if (pNode1->data <= pNode2->data)
		{
			pNode1 = pNode1->pNext; // pNode1指向下一个结点
		}
		else
		{
			// 临时保存pNode2的后继
			Node* pTemp = pNode2->pNext;
			// 将pNode2插入在pNode1的前面
			pNode2->pFront = pNode1->pFront;
			pNode1->pFront->pNext = pNode2;
			pNode2->pNext = pNode1;
			pNode1->pFront = pNode2;
			// pNode2后移
			pNode2 = pTemp;
		}
	}

	// 如果lst链表没有遍历完全
	if (pNode2 != lst.pRear)
	{
		// 把pNode2到lst.pRear的pFront部分连接到pRear的前面
		pNode2->pFront = pRear->pFront;
		pRear->pFront->pNext = pNode2;
		lst.pRear->pFront->pNext = pRear;
		pRear->pFront = lst.pRear->pFront;
	}

	// lst头尾相连
	lst.pHead->pNext = lst.pRear;
	lst.pRear->pFront = lst.pHead;
}

bool List::isOrder()
{
	/*if (0 == size() || 1 == size())
	{
		return true;
	}*/

	Node* pNode = pHead->pNext;
	while (pNode != pRear->pFront)
	{ 
		// 比较相邻的两个值
		if (pNode->data > pNode->pNext->data)
		{
			return false;
		}
		pNode = pNode->pNext;
	}
	return true;
}

void List::sort()
{
	if (0 == size() || 1 == size())
	{
		return;
	}
	// 插入排序
	int len = size();
	// 每次要插入的结点
	Node* pCur = pHead->pNext->pNext;
	for (int i = 1; i < len;i++)
	{
		Node* pNode = pCur;
		for (int j = i; j > 0;j--)
		{
			// 后一个与前一个比较
			if (pNode->data > pNode->pFront->data)
			{
				int t = pNode->data;
				pNode->data = pNode->pFront->data;
				pNode->pFront->data = t;
			}
			else
			{
				break;
			}
			pNode = pNode->pFront;
		}
		pCur = pCur->pNext;// 指向下一个要插入的数
	}
}
int List::size()
{
	if (empty())
	{
		return 0;
	}
	Node* pNode = pHead->pNext;
	int len = 0;
	while (pNode != pRear)
	{
		len++;
		pNode = pNode->pNext;
	}
	return len;
}