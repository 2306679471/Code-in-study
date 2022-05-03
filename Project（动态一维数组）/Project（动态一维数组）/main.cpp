#include"Array.h"
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int Maxsize;
	cout << "输入Maxsize的值" << endl;
	cin >> Maxsize;
	int* pArray = new int[Maxsize];
	cout << "按下1键开始输入数据" << endl;
	cout << "按下2键删除元素" << endl;
	cout << "按下3键输出排序好的元素" << endl;
	cout << "按下4键修改数据" << endl;
	cout << "按下0结束" << endl;
	CArray Array(Maxsize,pArray);
	while (bool b=1)
	{
		int input = _getch();
		switch (input)
		{
		case '1':Array.Input();
			break;
		case '2':
			int value;
			cout << "输入你要删除哪个数据" << endl;
			cin >> value;
			Array.Delete(value);
			Array.Query();
			break;
		case '3':
			Array.Sort();
			Array.Query();
			break;
		case'4':
			int pos, value;
			cout << "输入你要修改数据的位置以及修改的值" << endl;
			cin >> pos >> value;
			Array.Change(pos, value);
			Array.Query();
			break;
		case '0':
			b = 0;
			break;
		default:
			break;
		}
	}
	return 0;
}