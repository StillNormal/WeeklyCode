#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	int value;
	Node *prev;	//���ڵ�һ���ڵ㣬��Ϊ0
	Node *next;	//�������һ���ڵ㣬��Ϊ0
};


Node *remove_list_node(Node *&h, int i) {
	if(h == NULL) {
		return NULL;
	}

	int cnt = 0;
	for(Node* temp = h; temp != NULL; temp = temp->next) 
		cnt++;
	if(cnt < i || i <= 0)//������
		return NULL;
	
	if(cnt == 1) {//��ֻ��һ��
		Node* temp = h;
		h = NULL;
		return temp;
	}

	if(i == 1) {//���ص�һ��
		Node* temp = h;
		h = h->next;
		h->prev = NULL;
		return temp;
	}

	if(i == cnt) {//�������һ��
		Node* temp;
		for(temp = h; temp->next->next != NULL; temp = temp->next)
			;
		Node* result = temp->next;
		temp->next = NULL;
		return result;
	}
	
	Node* temp;
	for(temp = h; i > 1; temp = temp->next, i--)//�����м��
		;
	Node* pre = temp->prev;
	pre->next = temp->next;
	temp->next->prev = pre;
	return temp;
}	
		
int main() {
	Node* head = new Node;
	int num;
	cin >> num;
	cin >> head->value;
	head->prev = NULL;
	head->next = NULL;
	num--;

	for(int i = 0; i < num; i++) {//ͷ�巨 
		Node* p = new Node;
		cin >> p->value;
		if(head->next != NULL)
			head->next->prev = p;
		p->next = head->next;
		head->next = p;
		p->prev = head;
	}
		
	cout << "�����������:";
	for(Node* a = head; a != NULL; a = a->next)
		cout << a->value << " ";
	cout << endl;

	Node* ok = remove_list_node(head, 3);//�����ǲ���
	if(ok == NULL)
		cout << "ɾ�����Ϊ��" << endl;
	else 
		cout << "ɾ�����ֵΪ" << ok->value << endl;
	for(Node* a = head; a != NULL; a = a->next)
		cout << a->value << " ";

	system("pause");
}