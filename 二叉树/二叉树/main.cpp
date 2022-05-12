#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#define CC_SAFE_DELETE(p) do{delete p;p=nullptr;}while(0)
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
		//vec.push_back(NULL);
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
		//vec.push_back(NULL);
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
		//vec.push_back(NULL);
		return;
	}
	PostOrderTraverse(phead->lchild,vec);
	PostOrderTraverse(phead->rchild, vec);
	vec.push_back(phead->a);
}
void PreOrderTraverseBystack(Tree* root, vector<int>& vec)//前序迭代遍历
{
	/*if (!root) return;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty()) {
		Tree* ptemp = st.top();
		st.pop();
		vec.push_back(ptemp->a);
		if (ptemp->rchild) st.push(ptemp->rchild);
		if (ptemp->lchild) st.push(ptemp->lchild);
	}*/
	if (!root) return;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty())
	{
		Tree* ptemp = st.top();
		if (ptemp)
		{
			st.pop();
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
			st.pop();
			vec.push_back(st.top()->a);
			st.pop();
		}
	}
}
void InOrderTraverseBystack(Tree* root, vector<int>& vec)//中序迭代遍历
{
	/*if (!root) return;
	stack<Tree*> st;
	Tree* cur = root;
	while (cur !=nullptr || !st.empty()) {
		if (cur != nullptr) {
			st.push(cur);
			cur = cur->lchild;
		}
		else {
			cur = st.top();
			st.pop();
			vec.push_back(cur->a);
			cur = cur->rchild;
		}
	}*/
	if (!root) return;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty())
	{
		Tree* ptemp = st.top();
		if (ptemp)
		{
			st.pop();
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
			st.pop();
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
			st.pop();
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
			st.pop();
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
	root->lchild= Reversetreethroughrecursion(root->lchild);
	root->rchild= Reversetreethroughrecursion(root->rchild);
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
			pathst.push(path + "->" + to_string(ptemp->rchild->a));
		}
		if (ptemp->lchild)
		{
			treest.push(ptemp->lchild);
			pathst.push(path + "->" + to_string(ptemp->lchild->a));
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
	int Maxvalue=0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i]>Maxvalue) {
			maxindex = i;
			Maxvalue = nums[i];
		}
	}
	root->a = Maxvalue;
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
	if (!root || root->a == val) return root;
	if (root->a > val) return SearchBST(root->lchild,val);
	if (root->a < val) return SearchBST(root->rchild, val);
	return nullptr;
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
bool isSBT(Tree* root, vector<int>& vec) {//判断是否是搜索树
	vec.clear();
	InOrderTraverse(root, vec);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] <= vec[i - 1]) {
			return false;
		}
	}
	return true;
}
int getMinimumDifference(Tree* root, vector<int>& vec) {//获取最小绝对值
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
void SearchBSTtoMap(Tree* cur, unordered_map<int, int>& Map) {//遍历树，在map里创建对应的数据
	if (nullptr == cur) return;
	Map[cur->a] ++;
	SearchBSTtoMap(cur->lchild, Map);
	SearchBSTtoMap(cur->rchild, Map);
	return;
}
bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {//排序条件
	return a.second > b.second;
}
vector<int> findMore(Tree* root) {
	unordered_map<int, int> map; // key:元素，value:出现频率
	vector<int> result;
	if (root == NULL) return result;
	SearchBSTtoMap(root, map);
	vector<pair<int, int>> vec(map.begin(), map.end());
	sort(vec.begin(), vec.end(), cmp); // 给频率排个序
	result.push_back(vec[0].first);
	for (int i = 1; i < vec.size(); i++) {
		// 取最高的放到result数组中
		if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
		else break;
	}
	return result;
}
Tree* LowestCommonAncestor(Tree* root, Tree* p1,Tree* p2) {
	if (root == p1 || root == p2 || root == nullptr) {
		return root;
	}
	Tree* left = LowestCommonAncestor(root->lchild, p1, p2);//遍历左节点
	Tree* right = LowestCommonAncestor(root->rchild, p1, p2);/*遍历右节点*/
	if (left != nullptr && right != nullptr) {//如果当前节点左、右节点的返回值都不是空的话就说明当前节点就是最近的共同祖先
		return root;
	}
	if (left == nullptr) {//如果当前节点的左节点为空的话，说明结果是通过右节点返回的，所以返回右节点
		return right;
	}
	return left;
}//获取两个节点的最近公共祖先
void Insert(Tree*& root, int value) { //在搜索树中插入数据
	if (root == nullptr) {
		Tree* p = new Tree(value);
		root = p;
	}
	if (value > root->a) {
		Insert(root->rchild, value);
	}
	if (value < root->a) {
		Insert(root->lchild, value);
	}
}
Tree* DeleteNode(Tree* root, int value) {
	if (nullptr == root) {
		return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
	}
	if (root->a == value) {// 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
		if (root->lchild == nullptr && root->rchild == nullptr) {
			CC_SAFE_DELETE(root);
			return nullptr;
		}
		else if (root->lchild == nullptr) {// 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
			auto ptemp = root->rchild;
			CC_SAFE_DELETE(root);
			return ptemp;
		}
		else if (root->rchild == nullptr) {// 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
			auto ptemp = root->lchild;
			CC_SAFE_DELETE(root);
			return ptemp;
		}
		else {// 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
			// 并返回删除节点右孩子为新的根节点。
			Tree* ptemp = root->rchild;
			while (ptemp->lchild != nullptr) {// 找右子树最左面的节点
				ptemp = ptemp->lchild;
			}
			ptemp->lchild = root->lchild;// 把要删除的节点（root）左子树放在cur的左孩子的位置
			auto p = root;// 把root节点保存一下，下面来删除
			root = root->rchild;// 返回旧root的右孩子作为新root
			CC_SAFE_DELETE(p);// 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
			return root;
		}
		
	}
	if (root->a > value) root->lchild = DeleteNode(root->lchild, value);
	if (root->a < value) root->rchild = DeleteNode(root->rchild, value);
	return root;
}
Tree* trimBST(Tree* root, int low, int height) {//在[low,height]的区间里面修建二叉树
	if (root == nullptr) return nullptr;
	if (root->a < low) {
		return trimBST(root->rchild, low, height);
	}
	if (root->a > height) {
		return  trimBST(root->lchild, low, height);
	}
	root->lchild = trimBST(root->lchild, low, height);
	root->rchild = trimBST(root->rchild, low, height);
	return root;
}
Tree* TraversalVec(vector<int>& vec, int left, int right) {
	if (left > right) return nullptr;
	int mid = left + (right - left) / 2;
	Tree* root = new Tree(vec[mid]);
	root->lchild = TraversalVec(vec, left, mid - 1);//修剪数组
	root->rchild = TraversalVec(vec, mid + 1, right);
	return root; 
}
Tree* SortedArrayToBST(vector<int> vec) {//将有序的数组转换成二叉搜索树
	Tree* root = TraversalVec(vec, 0, vec.size() - 1);
	return root;
}
int pre;
void Traversal(Tree*& root) {
	if (!root) return;
	Traversal(root->rchild);
	root->a += pre;
	pre = root->a;
	Traversal(root->lchild);
}
void TraversalByit(Tree*& root) {
	if (!root) return ;
	stack<Tree*> st;
	st.push(root);
	while (!st.empty()) {
		Tree* ptemp = st.top();
		if (ptemp) {
			st.pop();
			if (ptemp->lchild) st.push(ptemp->lchild);
			st.push(ptemp);
			st.push(nullptr);
			if (ptemp->rchild) st.push(ptemp->rchild);
		}
		else {
			st.pop();
			st.top()->a += pre;
			pre = st.top()->a;
			st.pop(); 
		}
	}
}
Tree* ConverBST(Tree*& root) {
	pre = 0;
	TraversalByit(root);
	return root;
}
//二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数。
//二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数。
int main()
{
	/*vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	Tree* root;
	root = SortedArrayToBST(vec);
	vector<vector<int>> value;
	levelOrder(root, value);
	for (int i = 0; i < value.size(); i++) {
		for (int j = 0; j < value.at(i).size(); j++) {
			cout << value.at(i)[j] << "  ";
		}
		cout << endl;
	}*/
	Tree* root;
	create(root);
	root = ConverBST(root);
	vector<int> vec;
	InOrderTraverseBystack(root, vec);
	for each (int var in vec)
	{
		cout << var << "  ";
	}
	return 0;
}