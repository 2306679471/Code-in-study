#include<iostream>
#include"Myqueue.h"
using namespace std;
int main()
{
	Myqueue que;
	for (int i = 0; i <= 10; i++)
	{
		que.push(i);
	}
	cout << que.back() << endl;
	cout << que.front() << endl;
	return 0;
}