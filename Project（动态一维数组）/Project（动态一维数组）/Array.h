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
	int* Change(int pos,int value);//posΪҪ�޸ĵ�λ���±꣬valueΪҪ�޸ĵ�ֵ
private:
	int m_Maxsize;
	int* m_Parray=new int[m_Maxsize];
};

