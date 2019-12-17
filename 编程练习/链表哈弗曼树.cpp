#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	int val;
	Node* next;
};



void sort(Node* head) {//从小到大排序
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
	while(n > 1) {//集合中剩余1个结点以上
		sort(head);
		cnt += head->next->val + head->next->next->val;//对于霍夫曼树从根路径乘积和每次去两个加回一个计算一次 最后得出的最短路径值是一样的
		head->next->next->val = head->next->val + head->next->next->val;
		del = head->next;//每次排序后选第一第二个结点加到第二结点 再删去第一结点 模拟从最小堆中两次pop一次push
		head->next = head->next->next;
		delete del;
		n--;
	}
	
	//for(Node* temp = head->next; temp != NULL; temp = temp->next)//head头中不存值
	//	cout << temp->val << " ";		

	cout << cnt;

	system("pause");
}