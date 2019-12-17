#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

struct Node {
	char str[100];
	Node* next[10];
	int nextnum;
};

void print(Node* head, int space) {
	if (strlen(head->str) != 0) {//这里区分一下头结点不含有效字符
		for (int i = 0; i < space; i++)
			cout << " ";
		cout << head->str << endl;
	}
	for (int i = 0; i < head->nextnum; i++)//要求同一级有序
		for (int j = i+1; j < head->nextnum; j++)
			if (strcmp(head->next[i]->str, head->next[j]->str) > 0) {
				Node* temp = head->next[i];//不是仅交换字符串
				head->next[i] = head->next[j];
				head->next[j] = temp;
			}

	for (int i = 0; i < head->nextnum; i++)
		print(head->next[i], space+1+strlen(head->str));
	return;
}
int main() {
	int n;
	cin >> n;
	while (n != 0) {
		Node* head = new Node;
		head->nextnum = 0;
		head->str[0] = '\0';
		for (int i = 0; i < n; i++) {
			char s[100];
			cin >> s;
			char* p = strtok(s, "\\");
			Node* t = head;
			while (p != NULL) {
				bool hasfind = false;
				for (int j = 0; j < t->nextnum; j++) //不用整个树找 只需在某一层找
					if (strcmp(t->next[j]->str, p) == 0) {
					hasfind = true;
					t = t->next[j];
					break;
					}
				if (hasfind) {//有就不需创建
					p = strtok(NULL, "\\");
					continue;
				}
				Node* temp = new Node;
				strcpy(temp->str, p);
				temp->nextnum = 0;
				t->next[t->nextnum] = temp;
				t->nextnum++;
				t = t->next[t->nextnum - 1];
				p = strtok(NULL, "\\");
			}
		}
		print(head, -1);
		cout << endl;//格式要求
		cin >> n;
	}
	return 0;
}
/*
给你一串路径，譬如： a\b\c a\d\e b\cst d\ 你把这些路径中蕴含的目录结构给画出来，子目录直接列在父目录下面，并比父目录向右缩一格，就像这样： a   b     c   d      e b   cst d 同一级的需要按字母顺序排列，不能乱。
输入描述:
每个测试案例第一行为一个正整数n（n<=10）表示有n个路径，当n为0时，测试结束，接下来有n行，每行有一个字串表示一个路径，长度小于50。


输出描述:
输出目录结构，每一个测试样例的输出紧跟一个空行。

输入例子:
4
a\b\c
a\d\e
b\cst
d\
0

输出例子:
a
b
c
d
e
b
cst
d*/