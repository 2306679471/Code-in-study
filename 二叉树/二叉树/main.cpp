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
void PreOrderTraverseBystack(Tree* root, vector<int>& vec)//ǰ���������
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
void InOrderTraverseBystack(Tree* root, vector<int>& vec)//�����������
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
	root->lchild= Reversetreethroughrecursion(root->lchild);
	root->rchild= Reversetreethroughrecursion(root->rchild);
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
	return compare(left->lchild, right->rchild) && compare(left->rchild, right->lchild);
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
int getHeight(Tree* root)//��ȡ���ĸ߶�
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
bool isbalencetree(Tree* root)//�ж�һ�����Ƿ���һ��ƽ�������
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
bool isSameTree(Tree* tree1,Tree* tree2) {//�ж��������Ƿ���ͬ
	return compare(tree1, tree2);
}
int getSumOfLeftLeaves(Tree* root) {//��ȡ������Ҷ�ӽڵ��ֵ�ĺ�
	if (nullptr == root) return 0;
	int temp = 0;
	if (root->lchild && !root->lchild->lchild && !root->lchild->rchild) {
		temp = root->lchild->a;
	}
	return temp + getSumOfLeftLeaves(root->lchild) + getSumOfLeftLeaves(root->rchild);
}
int getSumOfRightLeaves(Tree* root) {//��ȡ������Ҷ�ӽڵ��ֵ�ĺ�
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
		Leftlen--;//����
	}
	return;
}
int getTheLeftBottomValueOfTree(Tree* root) {//��ȡ�����½ǵ�ֵ
	if (nullptr == root) return 0;
	traversal(root, 0);
	return maxvalue;
}
int getTheLeftBottomValueofTree(Tree* root) {//ͨ�����������ȡ���½�Ҷ�ӽڵ��ֵ
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
bool isEligible(Tree* root, int count) {//����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ���
	if (!root) return false;
	if (!root->lchild && !root->rchild &&count == root->a) {
		return true;
	}
	return isEligible(root->lchild, count - root->a) || isEligible(root->rchild, count - root->a);
}
Tree* CreateMaxTree(vector<int> nums) {//������������
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
Tree* MergeTwoTrees(Tree* root1, Tree* root2) {//�ϲ�������
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
Tree* SearchBST(Tree* root,int val) {//�����������ҵ����������Ľڵ�
	if (!root || root->a == val) return root;
	if (root->a > val) return SearchBST(root->lchild,val);
	if (root->a < val) return SearchBST(root->rchild, val);
	return nullptr;
}
Tree* SearchBSTByIteration(Tree* root, int val) {//ͬ�ϣ�������
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
bool isSBT(Tree* root, vector<int>& vec) {//�ж��Ƿ���������
	vec.clear();
	InOrderTraverse(root, vec);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] <= vec[i - 1]) {
			return false;
		}
	}
	return true;
}
int getMinimumDifference(Tree* root, vector<int>& vec) {//��ȡ��С����ֵ
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
void SearchBSTtoMap(Tree* cur, unordered_map<int, int>& Map) {//����������map�ﴴ����Ӧ������
	if (nullptr == cur) return;
	Map[cur->a] ++;
	SearchBSTtoMap(cur->lchild, Map);
	SearchBSTtoMap(cur->rchild, Map);
	return;
}
bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {//��������
	return a.second > b.second;
}
vector<int> findMore(Tree* root) {
	unordered_map<int, int> map; // key:Ԫ�أ�value:����Ƶ��
	vector<int> result;
	if (root == NULL) return result;
	SearchBSTtoMap(root, map);
	vector<pair<int, int>> vec(map.begin(), map.end());
	sort(vec.begin(), vec.end(), cmp); // ��Ƶ���Ÿ���
	result.push_back(vec[0].first);
	for (int i = 1; i < vec.size(); i++) {
		// ȡ��ߵķŵ�result������
		if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
		else break;
	}
	return result;
}
Tree* LowestCommonAncestor(Tree* root, Tree* p1,Tree* p2) {
	if (root == p1 || root == p2 || root == nullptr) {
		return root;
	}
	Tree* left = LowestCommonAncestor(root->lchild, p1, p2);//������ڵ�
	Tree* right = LowestCommonAncestor(root->rchild, p1, p2);/*�����ҽڵ�*/
	if (left != nullptr && right != nullptr) {//�����ǰ�ڵ����ҽڵ�ķ���ֵ�����ǿյĻ���˵����ǰ�ڵ��������Ĺ�ͬ����
		return root;
	}
	if (left == nullptr) {//�����ǰ�ڵ����ڵ�Ϊ�յĻ���˵�������ͨ���ҽڵ㷵�صģ����Է����ҽڵ�
		return right;
	}
	return left;
}//��ȡ�����ڵ�������������
void Insert(Tree*& root, int value) { //���������в�������
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
		return root; // ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
	}
	if (root->a == value) {// �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
		if (root->lchild == nullptr && root->rchild == nullptr) {
			CC_SAFE_DELETE(root);
			return nullptr;
		}
		else if (root->lchild == nullptr) {// �����������������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ �������Һ���Ϊ���ڵ�
			auto ptemp = root->rchild;
			CC_SAFE_DELETE(root);
			return ptemp;
		}
		else if (root->rchild == nullptr) {// ��������������Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
			auto ptemp = root->lchild;
			CC_SAFE_DELETE(root);
			return ptemp;
		}
		else {// ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ���������ŵ�ɾ���ڵ����������������ڵ�����ӵ�λ��
			// ������ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
			Tree* ptemp = root->rchild;
			while (ptemp->lchild != nullptr) {// ��������������Ľڵ�
				ptemp = ptemp->lchild;
			}
			ptemp->lchild = root->lchild;// ��Ҫɾ���Ľڵ㣨root������������cur�����ӵ�λ��
			auto p = root;// ��root�ڵ㱣��һ�£�������ɾ��
			root = root->rchild;// ���ؾ�root���Һ�����Ϊ��root
			CC_SAFE_DELETE(p);// �ͷŽڵ��ڴ棨���ﲻдҲ���ԣ���C++����ֶ��ͷ�һ�°ɣ�
			return root;
		}
		
	}
	if (root->a > value) root->lchild = DeleteNode(root->lchild, value);
	if (root->a < value) root->rchild = DeleteNode(root->rchild, value);
	return root;
}
Tree* trimBST(Tree* root, int low, int height) {//��[low,height]�����������޽�������
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
	root->lchild = TraversalVec(vec, left, mid - 1);//�޼�����
	root->rchild = TraversalVec(vec, mid + 1, right);
	return root; 
}
Tree* SortedArrayToBST(vector<int> vec) {//�����������ת���ɶ���������
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
//�������ڵ����ȣ�ָ�Ӹ��ڵ㵽�ýڵ�����·���ߵ�������
//�������ڵ�ĸ߶ȣ�ָ�Ӹýڵ㵽Ҷ�ӽڵ�����·���ߵ�������
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