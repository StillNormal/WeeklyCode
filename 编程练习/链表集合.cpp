#include<iostream>	
using namespace std;

struct Node {
	int val;
	Node* next;
};

Node* create(int num) {//ͷ�巨Ҫ��ͷ��㼴����ֵ ��Ȼ����һ����ʣ��������  ��β�巨������ν ͷ����������Ǵ����һ�����ʱ���赥������
	Node* head = new Node;
	head->next = NULL;
	for(int i = 0; i < num; i++) {
		Node* p = new Node;
		cin >> p->val;
		p->next = head->next;
		head->next = p;
	}	
	return head;
}
Node* create2(int num) {////����һ���������Ҫ��������˳�� ����ֻ�Ǵ����ṹ Ӧ��β�巨
	Node* head = new Node;
	head->next = NULL;
	cin >> head->val;
	if(num == 1)
		return head;

	Node* tail = head;
	for(int i = 0; i < num-1; i++) {
		Node* p = new Node;
		p->next = NULL;
		cin >> p->val;
		tail->next = p;
		tail = p;
	}
	return head;
}

Node* reverse(Node* h) {//��ת���� Ҳ���½�һ��������ͷ�巨�����൱��ת
	if(h == NULL || h->next == NULL)//��ͷ����Ҫ���ǵ�h->next->next
		return NULL;
	Node* p = h;
	Node* q = h->next;//qһֱ��p����Ľ��
	Node* temp;
	while(q != NULL) {//�ؼ�����p=p->next���������� һ��Ҫ����������
		temp = q->next;//q��Ϊ��Ҳ�ž�temp�Ҳ��������
		q->next = p;
		p = q;
		q = temp;
	}		
	h->next = NULL;
	return p;//��ʱq=NULL 
}		

void print(Node* h) {
	for(Node* p = h; p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;
}

bool hasLoop(Node* h) {
	if(h == NULL || h->next == NULL)
		return false;
	Node* stepBy1 = h;
	Node* stepBy2 = h;
	for(; stepBy2->next != NULL && stepBy2->next->next != NULL; stepBy1 = stepBy1->next, stepBy2 = stepBy2->next->next)//һ���������ļ������������һ����Ϊ��
		if(stepBy1 == stepBy2)//Ҫô�л���ⷵ�� Ҫôû���ߵĿ�ĵ���β����
			return true;
	return false;
}

int findLastK(Node* h, int k) {
	Node* p = h;
	Node* q = h;
	for(int i = 0; i < k; i++) {
		if(q == NULL)
			return -1;//�ܽ����û��k��
		q = q->next;
	}

	for(; q != NULL; q = q->next, p = p->next)
		;
	return p->val;
}

int findMid(Node* h) {
	if(h == NULL)
		return -1;
	if(h->next == NULL)
		return h->val;
	Node* p = h;
	Node* q = h;
	for(; q->next != NULL && q->next->next != NULL; q = q->next->next, p = p->next)
		;
	return p->val;
}
void sort(Node* h) {//ѡ������ ��Ҫnlgn���ù鲢����
	int temp;
	for(Node* p = h; p != NULL; p = p->next)
		for(Node* q = p->next; q != NULL; q = q->next)
			if(p->val > q->val) {
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}				
}
void deleteSame(Node* h) {//ɾ���ظ���ֵ Ҳ������������ɾ��
	for(Node* p = h; p != NULL; p = p->next)
		for(Node* q = p; q->next != NULL;) {//q��pָ��һ�� ������ʱq��Զ��q->next ����ɾ��ʱ����q��ɾq->next
			if(p->val == q->next->val) {
				Node* del = q->next;
				q->next = q->next->next;
				delete del;
			}
			else {
				q = q->next;//����ɾ��ʱqָ�벻�������
			}
		}
}
int main() {
	//Node* head = create(6);//����һ��6Ԫ������
	Node* head2 = create2(6);
	//print(head);
	//print(head2);

	head2 = reverse(head2);//��ûͷ����˳����β������
	print(head2);

	cout << "�Ƿ��л�:" << hasLoop(head2) << endl;

	cout << findLastK(head2,10) << " " << findLastK(head2, 3) << endl;

	cout << findMid(head2) << endl;

	sort(head2);
	print(head2);

	deleteSame(head2);
	print(head2);

	system("pause");
}