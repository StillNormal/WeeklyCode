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

void insert(Node*& head, Node*& tail, int xishu, int exp) {//���ﴫ����ָ��Ŀ���!!!!! ������ȫ�ֵ�ͷָ��
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
	sort(ahead);//���Ų��ô������� ��ѡ������

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
			if (ahead->xishu + bhead->xishu != 0)//����ע��
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
������������ʽ���������ǵĺ͡� ÿ������ʽ�����ɶ�������ʾ��ÿ�������У���һ��������ʾϵ������0�����ڶ���������ʾ����Ĵ����� ����3 3 5 -2 1 4 0��ʾ3x^5 - 2 * x + 4���е�һ��3��ʾ�ö���ʽ�����������Ա�ʾ��
��������:
����Ϊ���У��ֱ��ʾ��������ʽ����ʾÿ��������԰��մ�����С���������(��������ֵС��1000��ϵ������ֵС��10000)


�������:
���ս���˳�������ʾ�Ͷ���ʽ�������ԣ�ϵ��Ϊ0�������Բ���������������ɿո�ָ������һ�������Ժ���ӿո�

��������:
3 3 5 -2 1 4 0
4 2 3 -1 2 1 1 3 0

�������:
3 5 2 3 -1 2 -1 1 7 0*/