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
	// ��������ͷ�͸���β,��������
	// 1.����ͷ�ĺ���Ǹ���β
	pHead->pNext = pRear;
	// 2.����β��ǰ���Ǹ���ͷ
	pRear->pFront = pHead;
}


List::~List()
{
	// �ͷ����н����ڴ�
	clear();
	// �ͷŸ���ͷ�͸���β
	delete pHead;
	pHead = nullptr;
	delete pRear;
	pRear = nullptr;
}

void List::push_back(const int& val)
{
	// �����½��pNew,�����ڸ���β��ǰ��
	Node* pNew = new Node(val,pRear->pFront,pRear);
	// 1.�½���ǰ���Ǹ���β��ǰ��
	// pNew->pFront = pRear->pFront;
	// 2.�½��ĺ���Ǹ���β
	// pNew->pNext = pRear;
	// 3.����β��ǰ���ĺ�����½��
	pRear->pFront->pNext = pNew;
	// 4.����β��ǰ�����½��
	pRear->pFront = pNew;
}

void List::pop_front()
{
	// ���Բ���Ϊ��
	assert(!empty());// ����Ϊ��,�������ִ��,���Ϊ��,�����ж�

	// 1.����Ҫɾ���Ľ��
	Node* pDel = pHead->pNext;
	// 2.����ͷ�ĺ����pDel�ĺ��
	pHead->pNext = pDel->pNext;
	// 3.pDel�ĺ�̵�ǰ���Ǹ���ͷ
	pDel->pNext->pFront = pHead;
	// 4.�ͷ�pDelָ����ڴ�
	delete pDel;
	pDel = nullptr;
}

void List::print()
{
	// ����
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
		// ��ʱ������һ��
		Node* pTemp = pNode->pNext;
		delete pNode;
		pNode = pTemp;
	}
	// ���Ӹ���ͷ�͸���β
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
		// �жϵ�ǰ����ֵ�Ƿ����val
		if (val == pNode->data)
		{
			// ��ʱ������һ�����
			Node* pTemp = pNode->pNext;
			// pNode��ǰ���ĺ����pNode�ĺ��
			pNode->pFront->pNext = pNode->pNext;
			// pNode�ĺ�̵�ǰ����pNode��ǰ��
			pNode->pNext->pFront = pNode->pFront;
			// �ͷ�pNodeָ����ڴ�
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
		// �Ƚ���������Ԫ�ص�ֵ
		if (pNode->data == pNode->pNext->data)
		{
			// ��ʱ������һ�����
			Node* pDel = pNode->pNext;
			// pNode�ĺ�̵ĺ�̵�ǰ����pNode
			pDel->pNext->pFront = pNode;
			// pNode�ĺ����pNode��̵ĺ��
			pNode->pNext = pDel->pNext;
			// �ͷ�pNode����һ�����
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

	// ��������ͷ
	Node* pTemp = pHead;
	pHead = lst.pHead;
	lst.pHead = pTemp;

	// ��������β
	pTemp = pRear;
	pRear = lst.pRear;
	lst.pRear = pTemp;
}

void List::reverse()
{
	// û�н�����ֻ��һ�����
	/*if (0 == size() || 1 == size())
	{
		return;
	}*/
	// ���н�㽻��ǰ���ͺ�̵�ָ��
	Node* pNode = pHead;
	while (pNode != nullptr)
	{
		Node* pTemp = pNode->pNext;
		pNode->pNext = pNode->pFront;
		pNode->pFront = pTemp;

		pNode = pNode->pFront;// ԭ���ĺ��(���ڵ�ǰ��)
	}
	// ��������ͷβ��ָ��
	Node* pTemp = pHead;
	pHead = pRear;
	pRear = pTemp;
}

Iterator List::begin()
{
	// ����ָ�������ĵ�һ�����ĵ�����
	return Iterator(pHead->pNext);
}

Iterator List::end()
{
	// ָ������β���ĺ�һ�����ĵ�����
	return Iterator(pRear);
}

Iterator List::erase(Iterator pos)
{
	// 1.����Ҫɾ���Ľ��ָ��
	Node* pDel = pos.pNode;// ����.���ݳ�Ա
	// 2.pDel��ǰ���ĺ����pDel�ĺ��
	pDel->pFront->pNext = pDel->pNext;
	// 3.pDel�ĺ�̵�ǰ����pDel��ǰ��
	pDel->pNext->pFront = pDel->pFront;
	// 4.����pDel����һ�����
	Node* pTemp = pDel->pNext;
	// 5.�ͷ��ڴ�
	delete pDel;
	pDel = nullptr;
	// 6.����pTemp�ĵ�����
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
	// 1.����Ҫ�����λ��
	Node* pNode = pos.pNode;
	// 2.�����½��
	Node* pNew = new Node(val, pNode->pFront, pNode);
	// 3.pNode��ǰ���ĺ����pNew
	pNode->pFront->pNext = pNew;
	// 4.pNode��ǰ����pNew
	pNode->pFront = pNew;
	// 5.����ָ���½��ĵ�����
	return Iterator(pNew);
}

void List::splice(Iterator pos, List &lst)
{
	if (lst.empty())
	{
		return;
	}

	// ����Ҫ�����λ��
	Node* pNode = pos.pNode;
	lst.pHead->pNext->pFront = pNode->pFront;
	pNode->pFront->pNext = lst.pHead->pNext;
	lst.pRear->pFront->pNext = pNode;
	pNode->pFront = lst.pRear->pFront;

	// lstͷβ����
	lst.pHead->pNext = lst.pRear;
	lst.pRear->pFront = lst.pHead;
}

void List::merge(List &lst)
{
	assert(isOrder() && lst.isOrder());// ������������
	// pNode1������ǰ����
	Node* pNode1 = pHead->pNext;
	// pNode2����lst����
	Node* pNode2 = lst.pHead->pNext;
	// ѭ��
	while (pNode1 != pRear && pNode2 != lst.pRear)
	{
		if (pNode1->data <= pNode2->data)
		{
			pNode1 = pNode1->pNext; // pNode1ָ����һ�����
		}
		else
		{
			// ��ʱ����pNode2�ĺ��
			Node* pTemp = pNode2->pNext;
			// ��pNode2������pNode1��ǰ��
			pNode2->pFront = pNode1->pFront;
			pNode1->pFront->pNext = pNode2;
			pNode2->pNext = pNode1;
			pNode1->pFront = pNode2;
			// pNode2����
			pNode2 = pTemp;
		}
	}

	// ���lst����û�б�����ȫ
	if (pNode2 != lst.pRear)
	{
		// ��pNode2��lst.pRear��pFront�������ӵ�pRear��ǰ��
		pNode2->pFront = pRear->pFront;
		pRear->pFront->pNext = pNode2;
		lst.pRear->pFront->pNext = pRear;
		pRear->pFront = lst.pRear->pFront;
	}

	// lstͷβ����
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
		// �Ƚ����ڵ�����ֵ
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
	// ��������
	int len = size();
	// ÿ��Ҫ����Ľ��
	Node* pCur = pHead->pNext->pNext;
	for (int i = 1; i < len;i++)
	{
		Node* pNode = pCur;
		for (int j = i; j > 0;j--)
		{
			// ��һ����ǰһ���Ƚ�
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
		pCur = pCur->pNext;// ָ����һ��Ҫ�������
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