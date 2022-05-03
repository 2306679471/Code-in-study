#include <iostream>
#include "List.h"
using namespace std;
#include "Iterator.h"
/*
1.reverse
2.merge
3.sort(插入)
4.erase
*/
/*
1.结点类:数据域/指针域(前驱指针/后继指针)
2.链表类:头结点/尾结点
*/
int main()
{
	List l;
	// 在头部插入-1
	// l.insert(l.begin(), -1);
	l.push_back(-1);
	l.push_back(1);
	l.push_back(3);
	l.push_back(8);
	l.push_back(10);
	l.push_back(20);

	List other;
	other.push_back(2);
	other.push_back(4);
	other.push_back(6);

	//l.splice(l.begin(), other);
	l.merge(other);
	l.sort();
	l.print();
	cout << "*********************" << endl;
	other.print();


	//l.pop_front();
	//l.pop_front();
	//l.print();
	//l.clear();

	//l.push_back(3);
	//l.push_back(-1);
	//l.push_back(2);
	//l.push_back(2);
	//l.push_back(-5);
	//l.push_back(2);
	////l.remove(2);
	//l.unique();
	//l.print();


	//// 删除所有偶数
	//Iterator it = l.begin();
	//for (; it != l.end();)
	//{
	//	if (0 == (*it) % 2)
	//	{
	//		it = l.erase(it);
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}
	//l.print();
	return 0;
}