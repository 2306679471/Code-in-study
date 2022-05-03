#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*
������ȱ����� ǰ �� �������	�еݹ���ǵݹ飨���������ķ�ʽ
������ȱ�������ʵҲ�����ڶ�������һ��һ��ı���
�ݹ��˼·��
1.ȷ���ݹ麯���Ĳ���������ֵ
2.ȷ����ֹ����
3.ȷ������ݹ���߼� 
*/
struct Tree
{
	int a;
	Tree* lchild;
	Tree* rchild;
	Tree(int a) :a(a), lchild(nullptr), rchild(nullptr){}
};

void create(Tree* &root)
{
	int ch;
	cin>>ch;
	if (-1!=ch)
	{
		root = new Tree(ch);
		create(root->lchild);
		create(root->rchild);
	}
	else
	{
		root = nullptr;
	}
}
void PreOrderTraverse(Tree* phead,vector<int>& vec)
{
	if (phead == nullptr)
	{
		vec.push_back(NULL);
		return;
	}
	vec.push_back(phead->a);
	PreOrderTraverse(phead->lchild,vec);
	PreOrderTraverse(phead->rchild,vec);
}
void InOrderTraverse(Tree* phead, vector<int>& vec)
{
	if (phead == nullptr)
	{
		vec.push_back(NULL);
		return;
	}
	InOrderTraverse(phead->lchild, vec);
	vec.push_back(phead->a);
	InOrderTraverse(phead->rchild,vec);
}
void PostOrderTraverse(Tree* phead,vector<int>& vec)
{
	if (phead == nullptr)
	{
		vec.push_back(NULL);
		return;
	}
	PostOrderTraverse(phead->lchild,vec);
	PostOrderTraverse(phead->rchild, vec);
	vec.push_back(phead->a);
}
void PreOrderTraverseBystack(Tree* root, vector<int>& vec)//ǰ���������
{
	if (!root) return;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty())
	{
		Tree* ptemp = st.top();
		if (ptemp)
		{
			if (ptemp->rchild)
			{
				st.push(ptemp->rchild);
			}
			if (ptemp->lchild)
			{
				st.push(ptemp->lchild);
			}
			st.push(ptemp);
			st.push(nullptr);
		}
		else
		{
			vec.push_back(st.top()->a);
			st.pop();
		}
	}
}
void InOrderTraverseBystack(Tree* root, vector<int>& vec)//�����������
{
	if (!root) return;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty())
	{
		Tree* ptemp = st.top();
		if (ptemp)
		{
			if (ptemp->rchild)
			{
				st.push(ptemp->rchild);
			}
			st.push(ptemp);
			st.push(nullptr);
			if (ptemp->lchild)
			{
				st.push(ptemp->lchild);
			}
		}
		else
		{
			vec.push_back(st.top()->a);
			st.pop();
		}
	}
}
void PostOrderTraverseBystack(Tree* root, vector<int>& vec)//�����������
{
	if (!root) return;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty())
	{
		Tree* ptemp = st.top();
		if (ptemp)
		{
			st.push(ptemp);
			st.push(nullptr);
			if (ptemp->rchild)
			{
				st.push(ptemp->rchild);
			}
			if (ptemp->lchild)
			{
				st.push(ptemp->lchild);
			}
		}
		else
		{
			vec.push_back(st.top()->a);
			st.pop();
		}
	}
}
void levelOrder(Tree* root,vector<vector<int>>& vec)//�������
{
	queue<Tree* > qu;
	if (nullptr != root)
		qu.push(root);
	while (!qu.empty())
	{
		int size = qu.size();
		vector<int> Vector;
		for (int i = 0; i < size; i++)
		{
			Tree* ptemp = qu.front();
			qu.pop();
			Vector.push_back(ptemp->a);
			if (ptemp->lchild)
				qu.push(ptemp->lchild);
			if (ptemp->rchild)
				qu.push(ptemp->rchild);
		}
		vec.push_back(Vector); 
	}
}
void swap(Tree*& p1, Tree*& p2)
{
	int temp = p1->a;
	p1->a = p2->a;
	p2->a = temp;
}
Tree* Reversetreethroughrecursion(Tree* root)//ͨ���ݹ鷴ת��
{
	if (nullptr == root)
	{
		return root;
	}
	swap(root->lchild, root->rchild);
	Reversetreethroughrecursion(root->lchild);
	Reversetreethroughrecursion(root->rchild);
	return root;
}
Tree* Reversetreethroughiteration(Tree* root)//ͨ��������ת��
{
	stack<Tree*> st;
	if (!root)
	{
		cout << "��Ϊ��" << endl;
		return root;
	}
	st.push(root);
	while (!st.empty())
	{
		Tree* ptemp = st.top();
		if (ptemp)
		{
			st.pop();
			if (ptemp->rchild)
				st.push(ptemp->rchild);
			if (ptemp->lchild)
				st.push(ptemp->lchild);
			st.push(ptemp);
			st.push(nullptr);
		}
		else
		{
			st.pop();
			ptemp = st.top();
			st.pop();
			swap(ptemp->lchild, ptemp->rchild);
		}
	}
	return root;
}//ǰ�����
bool compare(Tree* left, Tree* right)
{
	if (left != nullptr&&right == nullptr)
	{
		return false;
	}
	else if (nullptr == left&&nullptr != right)
	{
		return false;
	}
	else if (nullptr == left&&nullptr == right)
	{
		return true;
	}
	else if (left->a != right->a)
	{
		return false;
	}
	bool outside = compare(left->lchild, right->rchild);   // ���������� ����������
	bool inside = compare(left->rchild, right->lchild);    // ���������ҡ� ����������
	bool isSame = outside && inside;                    // ���������С� ���������� ���߼�����
	return isSame;
}
bool isSymmetric(Tree* root)//�ж����ǲ��ǶԳƶ�����
{
	if (nullptr == root)
	{
		return true;
	}
	return compare(root->lchild, root->rchild);
}
int getmaxdepth(Tree* root)//�ݹ������ ǰ������ȣ�������߶�
{
	if (nullptr == root) return 0;
	return 1 + max(getmaxdepth(root->lchild), getmaxdepth(root->rchild));
}
int getmaxdepthiteration(Tree* root)
{
	if (nullptr == root) return 0;
	queue<Tree*> qu;
	qu.push(root);
	int depth = 0;
	while (!qu.empty())
	{
		int size = qu.size();
		depth++;
		for (int i = 0; i < size; i++)
		{
			Tree* ptemp = qu.front();
			qu.pop();
			if (ptemp->lchild) qu.push(ptemp->lchild);
			if (ptemp->rchild) qu.push(ptemp->rchild);
		}
	}
	return depth;
}
int getminDepth(Tree* root)
{
	if (nullptr == root) return 0;
	if (nullptr == root->lchild&&nullptr != root->rchild)
	{
		return 1 + getminDepth(root->rchild);
	}
	if (nullptr != root->lchild&&nullptr == root->rchild)
	{
		return 1 + getminDepth(root->lchild);
	}
	return 1 + min(getminDepth(root->lchild), getminDepth(root->rchild));
}
int getminDepthByIteration(Tree* root)
{
	if (nullptr == root) return 0;
	queue<Tree*> qu;
	qu.push(root);
	int depth = 0;
	while (!qu.empty())
	{
		int size = qu.size();
		depth++;
		for (int i = 0; i < size; i++)
		{
			Tree* ptemp = qu.front();
			qu.pop();
			if (ptemp->lchild) qu.push(ptemp->lchild);
			if (ptemp->rchild) qu.push(ptemp->rchild);
			if (!ptemp -> lchild && !ptemp -> rchild)
			{
				return depth;
			}
		}
	}
	return depth;
}
int getnodenum(Tree* root)//��ȡ�������Ľڵ����
{
	if (!root) return 0;
	return getnodenum(root->lchild) + getnodenum(root->rchild) + 1;
}
int getnodenumbyite(Tree* root)
{
	if (!root) return 0;
	queue<Tree*> qu;
	int num = 0;
	qu.push(root);
	while (!qu.empty())
	{
		int size = qu.size();
		for (int i = 0; i < size; i++)
		{
			Tree* ptemp = qu.front();
			qu.pop();
			num++;
			if (ptemp->lchild) 
				qu.push(ptemp->lchild);
			if (ptemp->rchild) 
				qu.push(ptemp->rchild);
		}
	}
	return num;
}
int getHeight(Tree* root)
{
	if (nullptr == root)
	{
		return 0;
	}
	int left = getHeight(root->lchild);
	if (left == -1) 
		return -1;
	int right = getHeight(root->rchild);
	if (right == -1)
		return -1;
	return abs(left - right) > 1 ? -1 : 1 + max(left, right);
}
bool isbalencetree(Tree* root)
{
	return getHeight(root) == -1 ? false : true;
}
vector<string> allpathoftree(Tree* root)
{
	stack<Tree*> treest;
	stack<string> pathst;
	vector<string> result;
	if (!root) return result;
	treest.push(root);
	pathst.push(to_string(root->a));
	while (!treest.empty())
	{
		Tree* ptemp = treest.top();
		treest.pop();
		string path = pathst.top();
		pathst.pop();
		if (nullptr == ptemp->lchild&&nullptr == ptemp->rchild)
		{
			result.push_back(path);
		}
		if (ptemp->rchild)
		{
			treest.push(ptemp->rchild);
			pathst.push(path + "->" + to_string(ptemp->a));
		}
		if (ptemp->lchild)
		{
			treest.push(ptemp->lchild);
			pathst.push(path + "->" + to_string(ptemp->a));
		}
	}
	return result;
}
//�������ڵ����ȣ�ָ�Ӹ��ڵ㵽�ýڵ�����·���ߵ�������
//�������ڵ�ĸ߶ȣ�ָ�Ӹýڵ㵽Ҷ�ӽڵ�����·���ߵ�������
int main()
{

	vector<int> Treevalue;
	Tree* root;
	create(root);
	/*PreOrderTraverse(root, Treevalue);
	for (int i = 0; i < Treevalue.size(); i++)
	{
		cout << Treevalue.at(i) << endl;
	}*/
	cout << getminDepthByIteration(root) << endl;
	return 0;
}