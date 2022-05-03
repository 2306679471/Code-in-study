#include"Array.h"
#include<iostream>
using namespace std;
CArray::CArray(int m_Maxsize,int* pArray)
{
	this->m_Maxsize = m_Maxsize;
	m_Parray = new int[m_Maxsize];
}
CArray::~CArray()
{
	delete m_Parray;
}
void CArray::Query()
{
	cout << "当前数组为：" << endl;
	for (int i = 0; i < m_Maxsize; i++)
		cout << m_Parray[i] << "  ";
	cout << endl;
}
int* CArray::Input()
{
	int a = 0, i = 0, count = 0;
	cout << "依次输入数组的元素，以-1结尾" << endl;
	while (cin >> a)
	{
		if (a == -1)
		{
			break;
		}
		else if (i < m_Maxsize)
		{
			m_Parray[i] = a;
			i++;
			count++;
		}
		else
		{
			int* p = new int[m_Maxsize * 2];
			for (int j = 0; j < m_Maxsize; j++)
			{
				p[j] = m_Parray[j];
			}
			delete[] m_Parray;
			m_Parray = p;
			m_Parray[i] = a;
			m_Maxsize = 2 * m_Maxsize;
			i++;
			count++;
		}
	}
	m_Maxsize = count;
	Query();
	return m_Parray;
}
int* CArray::Delete(int a)
{
	for (int i = 0; i < m_Maxsize; i++)
	{
		if (m_Parray[i] == a)
		{
			for (int j = i; j < m_Maxsize - 1; j++)
			{
				m_Parray[j] = m_Parray[j + 1];
			}
			(m_Maxsize)--;
		}
	}
	return m_Parray;
}
int* CArray::Sort()
{
	for (int i = 0; i < m_Maxsize - 1; i++) {
		int k = i;//先保存最开始的数 		
		for (int j = i; j < m_Maxsize; j++)
		{
			if (m_Parray[j] < m_Parray[k])
				k = j;
		}
		if (k != i) {
			int temp = m_Parray[k];
			m_Parray[k] = m_Parray[i];
			m_Parray[i] = temp;
		}
	}
	return m_Parray;
}
int* CArray::Change(int pos,int value)
{
	for (int i = 1; i < m_Maxsize; i++)
	{
		if (pos == i)
		{
			m_Parray[i-1] = value;
		}
	}
	return m_Parray;
}
