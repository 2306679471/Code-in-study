#pragma once
class Node;
// 迭代器:类似于指针,指向结点
/*
1.++/--:指向前一个/后一个结点
2.*:数据域
3.==/!=:判断两个迭代器是否相等
*/
class Iterator
{
public:
	friend class List;
	Iterator(Node* pNode = nullptr);
	~Iterator();
public:// 运算符重载
	Iterator& operator++();// 重载前置++:先自增再运算
	Iterator operator++(int);// 重载后置++:先运算再自增(返回自增之前的临时变量)
	// C++函数的编译:函数名_参数类型1_参数类型2_
	int& operator*();// 重载*运算符
	bool operator!=(const Iterator& other); // 重载!=运算符
private:
	Node* pNode; // pNode指向某个结点
};
