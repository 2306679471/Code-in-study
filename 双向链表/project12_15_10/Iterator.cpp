#include "Iterator.h"
#include "Node.h"

Iterator::Iterator(Node* pNode)
	:pNode(pNode)
{
}


Iterator::~Iterator()
{
}

Iterator& Iterator::operator++()
{
	pNode = pNode->pNext;// ָ����һ�����
	return *this;// ��������
}

Iterator Iterator::operator++(int)
{
	// ��ʱ���浱ǰ�����ֵ
	Iterator temp = *this;// thisָ��ǰ������
	// Iterator temp1 = pNode;// Iterator Node*(ת�����캯��)
	pNode = pNode->pNext;
	// ����û������֮ǰ�ĵ�����
	return temp;
}

int& Iterator::operator*()
{
	return pNode->data;
}

bool Iterator::operator!=(const Iterator& other)
{
	return pNode != other.pNode;
}