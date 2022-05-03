#pragma once
class CArray
{
public:
	CArray(int,int*);
	~CArray();
	int* Input();
	void Query();
	int* Delete(int);
	int* Sort();
	int* Change(int pos,int value);//pos为要修改的位置下标，value为要修改的值
private:
	int m_Maxsize;
	int* m_Parray=new int[m_Maxsize];
};

