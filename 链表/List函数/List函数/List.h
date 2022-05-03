#pragma once
// ����:Ϊ�˷�ֹͷ�ļ���������
#include"Iterator.h"
#define CC_SAFE_DELETE(p) do{delete p;p=nullptr;}while(0)
class Iterator;
// �Զ����˫��������
class List
{
public:
	List();
	~List();
	void push_back(const int &val); // ��β������Ԫ��
	void pop_front();				// ��ͷ��ɾ��
	void print();					// ��ӡ�����е�����
	bool empty() const;				// �ж�Ϊ��
	void clear();
	void remove(const int &val);
	void unique();
	void swap(List &lst);
	void reverse();
	void merge(List &lst);
	void sort();
	int size();
	int at(int pos);
	typedef Iterator iterator;
public:
	Iterator begin();			  // begin:����ָ��ͷ���ĵ�����
	Iterator end();				  // end:����ָ����β���ĵ�����
	Iterator erase(Iterator pos); // erase
	Iterator erase(Iterator start, Iterator end);
	Iterator insert(Iterator pos, const int &val);
	void splice(Iterator pos, List &lst); // splice// ���lst����
private:
	DouNode *pHead; // ָ����ͷ(���洢����)����ָ��
	DouNode *pRear; // ָ����β(���洢����)����ָ��
private:
	bool isOrder(); // �ж������Ƿ�����(����)
};
