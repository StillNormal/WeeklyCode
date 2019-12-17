#include<iostream>	
using namespace std;

struct Node {
	char val;
	Node* left;
	Node* right;
};
//递归调试断点设置可在子递归处 也可在一些都会访问的关键位置看那时全部数据信息 
Node* createTree(char pre[], int a, int b, char in[], int c, int d) {//根据前序和中序建树
	Node* root = new Node;
	root->val = pre[a];
	root->left = NULL;//未初始化的指针不是NULL 这会在遍历时造成困扰
	root->right = NULL;
	if(c == d) //叶子结点 递归退出条件
		return root;

	int i;
	for(i = c; i <= d; i++)//不是计数 右边要等号
		if(in[i] == pre[a])//先序第一个为根 再到中序去找
			break;
	if(i != c) //左子树不为空!
		root->left = createTree(pre, a+1, a+i-c, in, c, i-1);//该根结点左右孩子接递归返回子树的根结点
	if(i != d) //右子树不为空!
		root->right = createTree(pre, a+i-c+1, b, in, i+1, d);
	return root;
}
void Postorder(Node* head) {//后序遍历
	if(head == NULL)
		return;
	Postorder(head->left);
	Postorder(head->right);
	cout << head->val;
}
//一定要有中序的参与 因为它参与了左右子树的划分
int main() {
	char pre[20];
	cin >> pre;//测试输入 fdxeag
	char in[20];
	cin >> in;//xdefag

	Node* head = createTree(pre, 0, strlen(pre)-1, in, 0 , strlen(in)-1);//strlen不统计\0但是由于处理是字符数组下标还要-1

	Postorder(head);//xedgaf

	system("pause");
}