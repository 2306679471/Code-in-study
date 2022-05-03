#include<iostream>
using namespace std;
struct Node
{
	int a;
	int size;
	Node* pnext;
};
//1. 求单链表中结点的个数
//2. 将单链表反转
//3. 查找单链表中的倒数第K个结点（k > 0）
//4. 查找单链表的中间结点
//5. 从尾到头打印单链表
//6. 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
//7. 判断一个单链表中是否有环
//8. 判断两个单链表是否相交
//9. 求两个单链表相交的第一个节点
//10. 已知一个单链表中存在环，求进入环中的第一个节点
//11. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted
//12. 已知一个单链表中存在环,求环的长度
Node* CreateNodeList(int size,int *value)
{
	Node* phead = nullptr;
	phead->size = size;

	for (int i = 0; i < size; i++)
	{
		Node* pnew = (Node*)malloc(sizeof(Node));
		pnew->a = value[i];
		pnew->pnext = nullptr;
		if (nullptr == phead)
		{
			phead = pnew;
		}
		else//头插法创建链表
		{
			pnew->pnext = phead;
			phead = pnew;
		}
	}
	return phead;
}
int getlength(Node*& phead)
{
	return phead->size;
}
Node* reverselist(Node*& phead)//倒置链表
{
	if (nullptr==phead)
	{
		cout << "链表为空" << endl;
		return;
	}
	else if (phead->size<3)
	{
		if (nullptr == phead->pnext)
		{
			return;
		}
		else if (nullptr==phead->pnext->pnext)
		{
			phead->pnext->pnext = phead;
			phead->pnext = nullptr;
			return phead;
		}
	}
	else
	{
		Node* pnew = nullptr;
		Node* ptemp = phead->pnext;
		Node* ptempnext = ptemp->pnext; 
		pnew = phead;
		phead = ptemp;
		pnew->pnext = nullptr;
		while (nullptr != phead)
		{
			if (nullptr == ptempnext->pnext)
			{
				phead->pnext = pnew;
				pnew = phead;
				phead = ptempnext;
				phead->pnext = pnew;
				pnew = phead;
				phead = phead->pnext;
			}
			else
			{
				ptemp = ptemp->pnext;
				ptempnext = ptempnext->pnext;
				phead->pnext = pnew;
				pnew = phead;
				phead = ptemp;
			}
		}
		return pnew;
	}	
}
int Getthereciprocalelement(Node* phead,int pos)//pos代表倒数第几个元素
{
	Node* ptemp = phead;
	if (pos > phead->size)
	{
		cout << "位置输入有误" << endl;
		return;
	}
	else
	{
		if (pos == phead->size)
		{
			return phead->a;
		}
		else if (pos<phead->size)
		{
			for (int i = 1; i <= phead->size - pos + 1; i++)
			{
				ptemp = ptemp->pnext;
			}
			return ptemp->a;
		}
	}
}
Node* getmidnode(Node* phead)
{
	Node* ptemp = phead;
	if (phead->size % 2 == 0)
	{
		cout << "链表节点数为偶数，无中间节点" << endl;
		return;
	}
	else
	{
		for (int i = 1; i < phead->size / 2 + 1; i++)
		{
			ptemp = ptemp->pnext;
		}
		return ptemp;
	}
}
void reverseoutput(Node* phead)
{
	Node* ptemp = phead;
	for (int i = phead->size; i >= 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			ptemp = ptemp->pnext;
		}
		cout << ptemp->a << endl;
		ptemp = phead;
	}
}
void Listsort(Node*& phead)
{
	if (phead == nullptr || phead->pnext == nullptr)
	{
		return;
	}
	Node* ptemp = phead;
	Node* curMax = nullptr;// 用于保存每次循环比较出的最大值
	Node* pre = nullptr; //用于保存当前节点的前一个节点
	while (ptemp->pnext != curMax)
	{
		if (phead->a > ptemp->pnext->a)
		{
			phead = ptemp->pnext;
			ptemp->pnext = phead->pnext;
			phead->pnext = ptemp;
			pre = phead;
			ptemp = phead->pnext;
		}
		else
		{
			pre = phead;
			ptemp = phead->pnext;
		}


		while (ptemp->pnext != curMax)
		{
			if (ptemp->a > ptemp->pnext->a)
			{
				pre->pnext = ptemp->pnext;
				pre = ptemp->pnext;
				ptemp->pnext = pre->pnext;
				pre->pnext = ptemp;
				continue;
			}
			pre = ptemp;
			ptemp = ptemp->pnext;
		}
		curMax = ptemp;
		ptemp = phead;
	}
}
void Splicing(Node*& list1, Node* list2)//默认升序
{
	Node* ptemp = list1;
	for (; nullptr != ptemp->pnext; ptemp = ptemp->pnext);//把ptemp移动到list1 的末尾
	while (nullptr != list2->pnext)
	{
		ptemp->pnext = list2;
		ptemp = ptemp->pnext;
		list2 = list2->pnext;
	}
	Listsort(list1);
}
bool exitring(Node* phead)
{
	Node* slow = phead;
	Node* fast = phead;
	while (nullptr != fast->pnext || nullptr != fast->pnext->pnext)
	{
		slow = slow->pnext;
		fast = fast->pnext->pnext;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
bool isintersect(Node* list1, Node* list2)
{
	Node* ptemp1 = list1;
	Node* ptemp2 = list2;
	while (nullptr != ptemp1->pnext)
	{
		while (nullptr != ptemp2->pnext)
		{
			if (ptemp1->pnext==ptemp2->pnext)
			{
				return true;
			}
			ptemp2 = ptemp2->pnext;
		}
		ptemp1 = ptemp1->pnext;
	}
	return false;
}
void intersect(Node* list1, Node* list2)
{
	Node* ptemp1 = list1;
	Node* ptemp2 = list2;
	int count=1;
	while (nullptr != ptemp1->pnext)
	{
		while (nullptr != ptemp2->pnext)
		{
			if (ptemp1->pnext == ptemp2->pnext)
			{
				cout << "第一个交点在第" << count << "位" << endl;
				return;
			}
			ptemp2 = ptemp2->pnext;
		}
		count++;
		ptemp1 = ptemp1->pnext;
	}
	cout << "无交点" << endl;
}
int thefirstnodeofring(Node* phead)
{
	if (phead == nullptr || phead->pnext == nullptr || phead->pnext->pnext == nullptr)
	{
		return;
	}
	Node* h1 = phead->pnext;
	Node* h2 = phead->pnext->pnext;
	while (h1 != h2)
	{
		if (h2->pnext == nullptr || h2->pnext->pnext == nullptr)
			return 0;
		else
			h1 = h1->pnext;
		h2 = h2->pnext->pnext;
	}
	h2 = phead;
	int count = 1;
	while (h1 != h2)
	{
		h1 = h1->pnext;
		h2 = h2->pnext;
		count++;
	}
	cout << "入环点在第" << count << "位" << endl;
	return count;
}
void Delete(Node * pHead, Node * pToBeDeleted)
{
	if (pToBeDeleted == nullptr)
		return;
	if (pToBeDeleted->pnext != nullptr)
	{
		pToBeDeleted->a = pToBeDeleted->pnext->a; // 将下一个节点的数据复制到本节点，然后删除下一个节点  
		Node * temp = pToBeDeleted->pnext;
		pToBeDeleted->a = pToBeDeleted->pnext->a;
		delete temp;
	}
	else // 要删除的是最后一个节点  
	{
		if (pHead == pToBeDeleted) // 链表中只有一个节点的情况  
		{
			pHead = nullptr;
			delete pToBeDeleted;
		}
		else
		{
			Node * pNode = pHead;
			while (pNode->pnext != pToBeDeleted) // 找到倒数第二个节点  
				pNode = pNode->pnext;
			pNode->pnext = nullptr;
			delete pToBeDeleted;
		}
	}
}
int getlengthofring(Node* phead)
{
	if (!exitring(phead))
	{
		return 0;
	}
	else
	{
		int count = 1;
		Node* ptemp = phead;
		for (int i = 1; i <= thefirstnodeofring(phead); i++, ptemp = ptemp->pnext);
		Node* p = ptemp;
		ptemp = ptemp->pnext;
		while (p!=ptemp)
		{
			count++;
			ptemp = ptemp->pnext;
		}
		return count;
	}
}
int main()
{
	return 0;
}