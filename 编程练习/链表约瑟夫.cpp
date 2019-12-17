#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

struct Node {
	int num;
	Node* next;
};

int main() {
	int n;
	cin >> n;
	int step;
	cin >> step;
	Node* head = NULL;
	Node* tail = NULL;
	for (int i = 0; i < n; i++) {
		Node* p = new Node;
		p->num = i;
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
	tail->next = head;

	int cnt = n;
	Node* index = tail;//一开始提前一个
	while (cnt != 1) {
		Node* del = index;
		for (int i = 0; i < step - 1; i++) {
			index = index->next;
			del = del->next;
		}
		del = del->next;

		index->next = del->next;
		cout << del->num+1 << " ";//下标从1开始
		delete del;
		cnt--;
	}
	cout << index->num+1 << endl;
	system("pause");
	return 0;
}
