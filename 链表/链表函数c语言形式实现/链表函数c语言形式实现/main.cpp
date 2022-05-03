#include<iostream>
using namespace std;
struct Node
{
	int a;
	int size;
	Node* pnext;
};
//1. �������н��ĸ���
//2. ��������ת
//3. ���ҵ������еĵ�����K����㣨k > 0��
//4. ���ҵ�������м���
//5. ��β��ͷ��ӡ������
//6. ��֪����������pHead1 ��pHead2 �������򣬰����Ǻϲ���һ��������Ȼ����
//7. �ж�һ�����������Ƿ��л�
//8. �ж������������Ƿ��ཻ
//9. �������������ཻ�ĵ�һ���ڵ�
//10. ��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
//11. ����һ������ͷָ��pHead��һ�ڵ�ָ��pToBeDeleted��O(1)ʱ�临�Ӷ�ɾ���ڵ�pToBeDeleted
//12. ��֪һ���������д��ڻ�,�󻷵ĳ���
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
		else//ͷ�巨��������
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
Node* reverselist(Node*& phead)//��������
{
	if (nullptr==phead)
	{
		cout << "����Ϊ��" << endl;
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
int Getthereciprocalelement(Node* phead,int pos)//pos�������ڼ���Ԫ��
{
	Node* ptemp = phead;
	if (pos > phead->size)
	{
		cout << "λ����������" << endl;
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
		cout << "����ڵ���Ϊż�������м�ڵ�" << endl;
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
	Node* curMax = nullptr;// ���ڱ���ÿ��ѭ���Ƚϳ������ֵ
	Node* pre = nullptr; //���ڱ��浱ǰ�ڵ��ǰһ���ڵ�
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
void Splicing(Node*& list1, Node* list2)//Ĭ������
{
	Node* ptemp = list1;
	for (; nullptr != ptemp->pnext; ptemp = ptemp->pnext);//��ptemp�ƶ���list1 ��ĩβ
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
				cout << "��һ�������ڵ�" << count << "λ" << endl;
				return;
			}
			ptemp2 = ptemp2->pnext;
		}
		count++;
		ptemp1 = ptemp1->pnext;
	}
	cout << "�޽���" << endl;
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
	cout << "�뻷���ڵ�" << count << "λ" << endl;
	return count;
}
void Delete(Node * pHead, Node * pToBeDeleted)
{
	if (pToBeDeleted == nullptr)
		return;
	if (pToBeDeleted->pnext != nullptr)
	{
		pToBeDeleted->a = pToBeDeleted->pnext->a; // ����һ���ڵ�����ݸ��Ƶ����ڵ㣬Ȼ��ɾ����һ���ڵ�  
		Node * temp = pToBeDeleted->pnext;
		pToBeDeleted->a = pToBeDeleted->pnext->a;
		delete temp;
	}
	else // Ҫɾ���������һ���ڵ�  
	{
		if (pHead == pToBeDeleted) // ������ֻ��һ���ڵ�����  
		{
			pHead = nullptr;
			delete pToBeDeleted;
		}
		else
		{
			Node * pNode = pHead;
			while (pNode->pnext != pToBeDeleted) // �ҵ������ڶ����ڵ�  
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