#pragma once
struct DouNode
{
	DouNode()
	{
		pfront = pfront = nullptr;
	}
	int a;
	DouNode* pfront;//Ç°ÇýÖ¸Õë
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
	bool operator ==(Iterator & other);
	DouNode* getnode();
private:
	DouNode* node;
};