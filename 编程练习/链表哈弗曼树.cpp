#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	int val;
	Node* next;
};



void sort(Node* head) {//��С��������
	int temp;
	for(Node* p = head; p != NULL; p = p->next)
		for(Node* q = p; q != NULL; q = q->next)
			if(p->val > q->val) {
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}
}

int main() {
	int n;
	cin >> n;

	Node* head = new Node;
	head->next = NULL;
	for(int i = 0; i < n; i++) {
		Node* a = new Node;
		cin >> a->val;
		a->next = head->next;
		head->next = a;
	}
	
	int cnt = 0;
	Node* del;
	while(n > 1) {//������ʣ��1���������
		sort(head);
		cnt += head->next->val + head->next->next->val;//���ڻ��������Ӹ�·���˻���ÿ��ȥ�����ӻ�һ������һ�� ���ó������·��ֵ��һ����
		head->next->next->val = head->next->val + head->next->next->val;
		del = head->next;//ÿ�������ѡ��һ�ڶ������ӵ��ڶ���� ��ɾȥ��һ��� ģ�����С��������popһ��push
		head->next = head->next->next;
		delete del;
		n--;
	}
	
	//for(Node* temp = head->next; temp != NULL; temp = temp->next)//headͷ�в���ֵ
	//	cout << temp->val << " ";		

	cout << cnt;

	system("pause");
}