#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	int value;
	Node *prev;	//对于第一个节点，它为0
	Node *next;	//对于最后一个节点，它为0
};


Node *remove_list_node(Node *&h, int i) {
	if(h == NULL) {
		return NULL;
	}

	int cnt = 0;
	for(Node* temp = h; temp != NULL; temp = temp->next) 
		cnt++;
	if(cnt < i || i <= 0)//不存在
		return NULL;
	
	if(cnt == 1) {//就只有一个
		Node* temp = h;
		h = NULL;
		return temp;
	}

	if(i == 1) {//返回第一个
		Node* temp = h;
		h = h->next;
		h->prev = NULL;
		return temp;
	}

	if(i == cnt) {//返回最后一个
		Node* temp;
		for(temp = h; temp->next->next != NULL; temp = temp->next)
			;
		Node* result = temp->next;
		temp->next = NULL;
		return result;
	}
	
	Node* temp;
	for(temp = h; i > 1; temp = temp->next, i--)//返回中间的
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

	for(int i = 0; i < num; i++) {//头插法 
		Node* p = new Node;
		cin >> p->value;
		if(head->next != NULL)
			head->next->prev = p;
		p->next = head->next;
		head->next = p;
		p->prev = head;
	}
		
	cout << "输入测试用例:";
	for(Node* a = head; a != NULL; a = a->next)
		cout << a->value << " ";
	cout << endl;

	Node* ok = remove_list_node(head, 3);//以下是测试
	if(ok == NULL)
		cout << "删除结点为空" << endl;
	else 
		cout << "删除结点值为" << ok->value << endl;
	for(Node* a = head; a != NULL; a = a->next)
		cout << a->value << " ";

	system("pause");
}