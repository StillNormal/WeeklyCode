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
	if (strlen(head->str) != 0) {//��������һ��ͷ��㲻����Ч�ַ�
		for (int i = 0; i < space; i++)
			cout << " ";
		cout << head->str << endl;
	}
	for (int i = 0; i < head->nextnum; i++)//Ҫ��ͬһ������
		for (int j = i+1; j < head->nextnum; j++)
			if (strcmp(head->next[i]->str, head->next[j]->str) > 0) {
				Node* temp = head->next[i];//���ǽ������ַ���
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
				for (int j = 0; j < t->nextnum; j++) //������������ ֻ����ĳһ����
					if (strcmp(t->next[j]->str, p) == 0) {
					hasfind = true;
					t = t->next[j];
					break;
					}
				if (hasfind) {//�оͲ��贴��
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
		cout << endl;//��ʽҪ��
		cin >> n;
	}
	return 0;
}
/*
����һ��·����Ʃ�磺 a\b\c a\d\e b\cst d\ �����Щ·�����̺���Ŀ¼�ṹ������������Ŀ¼ֱ�����ڸ�Ŀ¼���棬���ȸ�Ŀ¼������һ�񣬾��������� a   b     c   d      e b   cst d ͬһ������Ҫ����ĸ˳�����У������ҡ�
��������:
ÿ�����԰�����һ��Ϊһ��������n��n<=10����ʾ��n��·������nΪ0ʱ�����Խ�������������n�У�ÿ����һ���ִ���ʾһ��·��������С��50��


�������:
���Ŀ¼�ṹ��ÿһ�������������������һ�����С�

��������:
4
a\b\c
a\d\e
b\cst
d\
0

�������:
a
b
c
d
e
b
cst
d*/