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
	pNode = pNode->pNext;// 指向下一个结点
	return *this;// 返回自身
}

Iterator Iterator::operator++(int)
{
	// 临时保存当前对象的值
	Iterator temp = *this;// this指向当前迭代器
	// Iterator temp1 = pNode;// Iterator Node*(转换构造函数)
	pNode = pNode->pNext;
	// 返回没有自增之前的迭代器
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