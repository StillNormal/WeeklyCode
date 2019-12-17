#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

struct Node {
	int xishu;
	int exp;
	Node* next;
};

void insert(Node*& head, Node*& tail, int xishu, int exp) {//这里传的是指针的拷贝!!!!! 或者用全局的头指针
	Node* p = new Node;
	p->xishu = xishu;
	p->exp = exp;
	p->next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

void sort(Node* head) {
	for (Node* p = head; p != NULL; p = p->next)
		for (Node* q = p->next; q != NULL; q = q->next) {
		if (p->exp < q->exp) {
			int temp = p->exp;
			p->exp = q->exp;
			q->exp = temp;
			temp = p->xishu;
			p->xishu = q->xishu;
			q->xishu = temp;
		}
		}
}
int main() {
	int m;
	cin >> m;
	Node* ahead = NULL;
	Node* atail = NULL;
	for (int i = 0; i < m; i++) {
		int xishu, exp;
		cin >> xishu >> exp;
		insert(ahead, atail, xishu, exp);
	}
	sort(ahead);//快排不好处理链表 用选择排序

	int n;
	cin >> n;
	Node* bhead = NULL;
	Node* btail = NULL;
	for (int i = 0; i < n; i++) {
		int xishu, exp;
		cin >> xishu >> exp;
		insert(bhead, btail, xishu, exp);
	}
	sort(bhead);

	Node* chead = NULL;
	Node* ctail = NULL;
	while (ahead != NULL && bhead != NULL) {
		if (ahead->exp > bhead->exp) {
			insert(chead, ctail, ahead->xishu, ahead->exp);
			ahead = ahead->next;
		}
		else if (ahead->exp < bhead->exp) {
			insert(chead, ctail, bhead->xishu, bhead->exp);
			bhead = bhead->next;
		}
		else {
			if (ahead->xishu + bhead->xishu != 0)//这里注意
				insert(chead, ctail, ahead->xishu + bhead->xishu, ahead->exp);
			ahead = ahead->next;
			bhead = bhead->next;
		}
	}
	while (ahead != NULL) {
		insert(chead, ctail, ahead->xishu, ahead->exp);
		ahead = ahead->next;
	}
	while (bhead != NULL) {
		insert(chead, ctail, bhead->xishu, bhead->exp);
		bhead = bhead->next;
	}

	while (chead->next != NULL) {
		cout << chead->xishu << " " << chead->exp << " ";
		chead = chead->next;
	}
	cout << chead->xishu << " " << chead->exp << endl;
	return 0;
}
/*
输入两个多项式，计算它们的和。 每个多项式有若干对整数表示，每组整数中，第一个整数表示系数（非0），第二个整数表示该项的次数。 如由3 3 5 -2 1 4 0表示3x^5 - 2 * x + 4其中第一个3表示该多项式由三个整数对表示。
输入描述:
输入为两行，分别表示两个多项式。表示每项的整数对按照次数大小降序给出。(次数绝对值小于1000，系数绝对值小于10000)


输出描述:
按照降次顺序输出表示和多项式的整数对（系数为0的整数对不用输出，整数对由空格分隔，最后一个整数对后不添加空格）

输入例子:
3 3 5 -2 1 4 0
4 2 3 -1 2 1 1 3 0

输出例子:
3 5 2 3 -1 2 -1 1 7 0*/