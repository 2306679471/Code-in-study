#pragma once
/*
写类的四步:
1.数据成员
2.四大默认成员函数
  构造:初始化
  析构:释放内存
  拷贝构造:深拷贝
  赋值:与深拷贝同时
3.成员函数
4.增加成员
*/
class Node
{
public:
	friend class List;// List作为Node类的友元类
	friend class Iterator;
	Node();
	// 缺省只能写在声明中
	Node(int data, Node* pFront = nullptr, Node* pNext = nullptr);
	~Node();
private:
	int data;// 数据域
	Node* pFront;// 前驱指针:指向上一个结点
	Node* pNext;// 后继指针:指向下一个结点
};

