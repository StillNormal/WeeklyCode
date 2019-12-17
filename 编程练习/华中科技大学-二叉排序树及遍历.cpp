#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

struct Node {
	int val;
	Node* left;
	Node* right;
};

void preOrder(Node* h) {
	if (h == NULL)
		return;
	cout << h->val << " ";
	preOrder(h->left);
	preOrder(h->right);
}
void inOrder(Node* h) {
	if (h == NULL)
		return;
	inOrder(h->left);
	cout << h->val << " ";
	inOrder(h->right);
}
void postOrder(Node* h) {
	if (h == NULL)
		return;
	postOrder(h->left);
	postOrder(h->right);
	cout << h->val << " ";
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		Node* head = new Node;
		cin >> head->val;
		head->left = head->right = NULL;
		for (int i = 1; i < n; i++) {
			Node* p = new Node;
			cin >> p->val;
			p->left = p->right = NULL;
			Node* temp = head;
			while (1) {
				if (temp->val > p->val) {
					if (temp->left != NULL)
						temp = temp->left;
					else {
						temp->left = p;
						break;
					}
				}
				else if (temp->val < p->val){
					if (temp->right != NULL)
						temp = temp->right;
					else {
						temp->right = p;
						break;
					}
				}
				else//相同的值是不会被加入排序树的
					break;
			}
		}

		preOrder(head); cout << endl;
		inOrder(head); cout << endl;
		postOrder(head); cout << endl;
	}
	return 0;
}
/*
输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
输入描述:
输入第一行包括一个整数n(1<=n<=100)。
接下来的一行包括n个整数。


输出描述:
可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
每种遍历结果输出一行。每行最后一个数据之后有一个空格。

输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。

输入例子:
5
1 6 5 9 8

输出例子:
1 6 5 9 8
1 5 6 8 9
5 8 9 6 1 */