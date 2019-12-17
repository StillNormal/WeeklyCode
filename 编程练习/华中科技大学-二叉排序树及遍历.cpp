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
				else//��ͬ��ֵ�ǲ��ᱻ������������
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
����һϵ������������������������������ǰ�����򣬺��������
��������:
�����һ�а���һ������n(1<=n<=100)��
��������һ�а���n��������


�������:
�����ж���������ݣ�����ÿ�����ݣ�����Ŀ�������ݽ���һ�����������������Զ�������������ǰ������ͺ��������
ÿ�ֱ���������һ�С�ÿ�����һ������֮����һ���ո�

�����п������ظ�Ԫ�أ���������Ķ����������������ظ�Ԫ�ز��������

��������:
5
1 6 5 9 8

�������:
1 6 5 9 8
1 5 6 8 9
5 8 9 6 1 */