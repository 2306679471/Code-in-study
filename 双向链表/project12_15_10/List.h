#pragma once
// 声明:为了防止头文件互相引用
class Node;
class Iterator;
// 自定义的双向链表类
class List
{
public:
	List();
	~List();
	void push_back(const int &val); // 从尾部插入元素
	void pop_front();				// 从头部删除
	void print();					// 打印链表中的数据
	bool empty() const;				// 判断为空
	void clear();
	void remove(const int &val);
	void unique();
	void swap(List &lst);
	void reverse();
	void merge(List &lst);
	void sort();
	int size();

public:
	Iterator begin();			  // begin:返回指向头结点的迭代器
	Iterator end();				  // end:返回指向辅助尾结点的迭代器
	Iterator erase(Iterator pos); // erase
	Iterator erase(Iterator start, Iterator end);
	Iterator insert(Iterator pos, const int &val);
	void splice(Iterator pos, List &lst); // splice// 清空lst链表
private:
	Node *pHead; // 指向辅助头(不存储数据)结点的指针
	Node *pRear; // 指向辅助尾(不存储数据)结点的指针
private:
	bool isOrder(); // 判断链表是否有序(升序)
};
