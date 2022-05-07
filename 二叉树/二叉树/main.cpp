#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*
深度优先遍历： 前 中 后序遍历	有递归跟非递归（迭代法）的方式
广度优先遍历：其实也就是在二叉树上一层一层的遍历
递归的思路：
1.确定递归函数的参数跟返回值
2.确定终止条件
3.确定单层递归的逻辑 
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
void PreOrderTraverseBystack(Tree* root, vector<int>& vec)//前序迭代遍历
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
void InOrderTraverseBystack(Tree* root, vector<int>& vec)//中序迭代遍历
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
void PostOrderTraverseBystack(Tree* root, vector<int>& vec)//后序迭代遍历
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
void levelOrder(Tree* root,vector<vector<int>>& vec)//层序遍历
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
Tree* Reversetreethroughrecursion(Tree* root)//通过递归反转树
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
Tree* Reversetreethroughiteration(Tree* root)//通过迭代反转树
{
	stack<Tree*> st;
	if (!root)
	{
		cout << "树为空" << endl;
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
}//前序遍历
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
	return compare(left->lchild, right->rchild) && compare(left->rchild, right->lchild);
}
bool isSymmetric(Tree* root)//判断树是不是对称二叉树
{
	if (nullptr == root)
	{
		return true;
	}
	return compare(root->lchild, root->rchild);
}
int getmaxdepth(Tree* root)//递归求深度 前序求深度，后序球高度
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
int getnodenum(Tree* root)//获取二叉树的节点个数
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
int getHeight(Tree* root)//获取树的高度
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
bool isbalencetree(Tree* root)//判断一棵树是否是一个平衡二叉树
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
bool isSameTree(Tree* tree1,Tree* tree2) {//判断两棵树是否相同
	return compare(tree1, tree2);
}
int getSumOfLeftLeaves(Tree* root) {//获取所有左叶子节点的值的和
	if (nullptr == root) return 0;
	int temp = 0;
	if (root->lchild && !root->lchild->lchild && !root->lchild->rchild) {
		temp = root->lchild->a;
	}
	return temp + getSumOfLeftLeaves(root->lchild) + getSumOfLeftLeaves(root->rchild);
}
int getSumOfRightLeaves(Tree* root) {//获取所有右叶子节点的值的和
	if (nullptr == root) return 0;
	int temp = 0;
	if (root->rchild && !root->rchild->lchild && !root->rchild->rchild) {
		temp = root->rchild->a;
	}
	return temp + getSumOfRightLeaves(root->lchild) + getSumOfRightLeaves(root->rchild);
}
int maxlen = INT_MIN;
int maxvalue;
void traversal(Tree* root, int Leftlen) {
	if (!root->lchild && !root->rchild) {
		if (maxlen < Leftlen) {
			maxlen = Leftlen;
			maxvalue = root->a;
		}
		return;
	}
	if (root->lchild) {
		Leftlen++;
		traversal(root->lchild, Leftlen);
		Leftlen--;
	}
	if (root->rchild) {
		Leftlen++;
		traversal(root->rchild, Leftlen);
		Leftlen--;//回溯
	}
	return;
}
int getTheLeftBottomValueOfTree(Tree* root) {//获取树左下角的值
	if (nullptr == root) return 0;
	traversal(root, 0);
	return maxvalue;
}
int getTheLeftBottomValueofTree(Tree* root) {//通过层序遍历获取左下角叶子节点的值
	queue<Tree*> que;
	if (!root) que.push(root);
	int result;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			Tree* ptemp = que.front();
			que.pop();
			if (0 == i) result = ptemp->a;
			if (ptemp->lchild) que.push(ptemp->lchild);
			if (ptemp->rchild) que.push(ptemp->rchild);
		}
	}
	return result;
}
bool isEligible(Tree* root, int count) {//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和
	if (!root) return false;
	if (!root->lchild && !root->rchild &&count == root->a) {
		return true;
	}
	return isEligible(root->lchild, count - root->a) || isEligible(root->rchild, count - root->a);
}
Tree* CreateMaxTree(vector<int> nums) {//创建最大二叉树
	Tree* root = new Tree(0);
	if (nums.size() == 1) {
		root->a = nums[0];
		return root;
	}
	int maxindex=0;
	int maxvalue=0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i]>maxvalue) {
			maxindex = i;
			maxvalue = nums[i];
		}
	}
	root->a = maxvalue;
	if (maxindex > 0) {
		vector<int> newVec(nums.begin(), nums.begin() + maxindex);
		root->lchild = CreateMaxTree(newVec);
	}
	if (maxindex < nums.size() - 1) {
		vector<int> newVec(nums.begin() + maxindex+1, nums.end());
		root->rchild = CreateMaxTree(newVec);
	}
	return root;
}
Tree* MergeTwoTrees(Tree* root1, Tree* root2) {//合并两棵树
	if (!root1 && !root2) {
		return nullptr;
	}
	if (!root1) {
		return root2;
	}
	if (!root2) {
		return root1;
	}
	root1->a += root2->a;
	root1->lchild = MergeTwoTrees(root1->lchild, root2->lchild);
	root1->rchild = MergeTwoTrees(root1->rchild, root2->rchild);
	return root1;
}
Tree* MergeTwoTreesByiterarion(Tree* root1, Tree* root2) {
	if (!root1) {
		return root2;
	}
	if (!root2) {
		return root1;
	}
	queue<Tree*> qu;
	qu.push(root1);
	qu.push(root2);
	while (!qu.empty()) {
		Tree* p1 = qu.front();
		qu.pop();
		Tree* p2 = qu.front();
		qu.pop();
		if (p1->lchild && p2->lchild) {
			qu.push(p1->lchild);
			qu.push(p2->lchild);
		}
		if (p1->rchild && p2->rchild) {
			qu.push(p1->rchild);
			qu.push(p2->rchild);
		}
		if (!p1->lchild &&p2->lchild) {
			p1->lchild = p2->lchild;
		}
		if (p1->rchild && !p2->rchild) {
			p1->rchild = p2->rchild;
		}

	}
	return root1;
}
Tree* SearchBST(Tree* root,int val) {//在有序树中找到符合条件的节点
	if (!root || root->a == val) {
		return root;
	}
	return root->a > val ? SearchBST(root->lchild, val) : SearchBST(root->rchild, val);
}
Tree* SearchBSTByIteration(Tree* root, int val) {//同上，迭代法
	Tree* ptemp = root;
	while (ptemp) {
		if (ptemp->a > val) {
			ptemp = ptemp->lchild;
		}
		else if (ptemp->a < val) {
			ptemp = ptemp->rchild;
		}
		else {
			return ptemp;
		}
	}
	return nullptr;
}
bool isSBT(Tree* root, vector<int>& vec) {
	vec.clear();
	InOrderTraverse(root, vec);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] <= vec[i - 1]) {
			return false;
		}
	}
	return true;
}
int getMinimumDifference(Tree* root, vector<int>& vec) {
	vec.clear();
	InOrderTraverse(root, vec);
	int result = INT_MAX;
	if (vec.size() < 2) {
		return 0;
	}
	for (int i = 1; i < vec.size(); i++) {
		result = min(result, abs(vec[i] - vec[i - 1]));
	}
	return result;
}
//二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数。
//二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数。
int main()
{
	vector<vector<int>> Treevalue;
	Tree* root;
	//create(root);
	/*PreOrderTraverse(root, Treevalue);
	for (int i = 0; i < Treevalue.size(); i++)
	{
		cout << Treevalue.at(i) << endl;
	}*/
	//cout << getminDepthByIteration(root) << endl;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(0);
	root = CreateMaxTree(nums);
	levelOrder(root, Treevalue);
	for (int i = 0; i < Treevalue.size(); i++) {
		for (int j = 0; j < Treevalue.at(i).size(); j++) {
			cout << Treevalue.at(i).at(j);
		}
		cout << endl;
	}
	return 0;
}