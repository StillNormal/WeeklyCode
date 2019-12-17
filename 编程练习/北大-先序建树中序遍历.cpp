#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

struct Node {
	char val;
	Node* left;
	Node* right;
};
void inOrder(Node* h) {
	if (h == NULL)
		return;
	inOrder(h->left);
	cout << h->val << " ";
	inOrder(h->right);
}
int i = 0;
Node* create(char* str) {
	if (str[i] == '\0')
		return NULL;

	Node* h;
	if (str[i] == '#') {
		h = NULL;
		return h;
	}
	h = new Node;
	h->val = str[i];
	i++;
	h->left = create(str);//create(h->left, str, i+1);����д˼·����  ����new�������ݷ��ز���
	i++;
	h->right = create(str);//create(h->right, str, i+2);
	return h;
}
int main() {
	char str[1000];
	while (scanf("%s", str) != EOF) {
		i = 0;
		Node* head = create(str);
		inOrder(head);
		cout << endl;//������ܶ� ����û�� �������任�зָ������Խ����û��
	}
	return 0;
}