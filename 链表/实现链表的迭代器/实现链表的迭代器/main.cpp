#include"Mydoulist.h"
#include"Iterator.h"
#include<iostream>
using namespace std;
int main()
{
	int a[10] = {46,1,45,9,4,5,1,2,6,7};
	MyDouList doulist(a, 10);
	MyDouList::iterator it(doulist.begin());
	it.print(doulist.end());
	return 0;
}