#include"Array.h"
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int Maxsize;
	cout << "����Maxsize��ֵ" << endl;
	cin >> Maxsize;
	int* pArray = new int[Maxsize];
	cout << "����1����ʼ��������" << endl;
	cout << "����2��ɾ��Ԫ��" << endl;
	cout << "����3���������õ�Ԫ��" << endl;
	cout << "����4���޸�����" << endl;
	cout << "����0����" << endl;
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
			cout << "������Ҫɾ���ĸ�����" << endl;
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
			cout << "������Ҫ�޸����ݵ�λ���Լ��޸ĵ�ֵ" << endl;
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