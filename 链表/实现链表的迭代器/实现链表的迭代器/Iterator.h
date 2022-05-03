#pragma once
struct DouNode
{
	int a;
	DouNode* pfront;
	DouNode* pnext;
};
class Iterator
{
public:
	Iterator() :node(nullptr){}
	Iterator(DouNode* node) :node(node){}
	Iterator(const Iterator& it) :node(it.node){}
	int operator * ()const;

	void operator ++ ();
	Iterator operator ++ (int);
	Iterator operator + (int n);
	DouNode operator [] (int n);
	Iterator operator=(DouNode* phead);
	Iterator operator=(Iterator t);
	bool operator!=(Iterator &t);
	void print(DouNode* end);
private:
	DouNode* node;
};