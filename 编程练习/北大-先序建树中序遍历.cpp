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
	h->left = create(str);//create(h->left, str, i+1);这样写思路不对  并且new出的内容返回不了
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
		cout << endl;//多输出很多 程序没错 多半是这句换行分割多个测试结果的没加
	}
	return 0;
}