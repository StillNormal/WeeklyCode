#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

class IntSet {
	Node* head;
	public :
		IntSet();
		void insert(int x);
		bool IsEqual(IntSet a);
		IntSet union2(IntSet a, IntSet b);
		IntSet incorporate2(IntSet a, IntSet b);
		void print();

		bool find(int x);
};
bool IntSet::find(int x) {
	for(Node* p = head; p != NULL; p = p->next)
		if(p->val == x)
			return true;
	return false;
}
void IntSet::insert(int x) {
	if(!find(x)) {
		Node* p = new Node;
		p->val = x;
		p->next = head->next;
		head->next = p;
	}
}
IntSet::IntSet() {
	head = new Node;
	head->val = -1;
	head->next = NULL;
}

bool IntSet::IsEqual(IntSet a) {
	bool flag = true;
	for(Node* p = a.head; p != NULL; p = p->next)
		if(!find(p->val)) 
			return false;
	for(Node* q = head; q != NULL; q = q->next)
		if(!a.find(q->val))
			return false;
	return true;
}

IntSet IntSet::union2(IntSet a, IntSet b) {
	IntSet temp;
	for(Node* p = a.head; p != NULL; p = p->next)
		if(b.find(p->val))
			temp.insert(p->val);
	return temp;
}

IntSet IntSet::incorporate2(IntSet a, IntSet b) {
	IntSet temp;
	for(Node* p = a.head; p != NULL; p = p->next)
		temp.insert(p->val);
	for(Node* p = b.head; p != NULL; p = p->next)
		temp.insert(p->val);
	return temp;
}
void IntSet::print() {
	for(Node* p = head->next; p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;
}

int main() {
	IntSet s1, s2, s3, s4;
	int x;
	for (cin >> x; x != 0; cin >> x)
		s1.insert(x);//�� s1 �в���Ԫ��
	for (cin >> x; x != 0; cin >> x)
		s2.insert(x);//�� s2 �в���Ԫ��
	if (s1.IsEqual(s2))//�Ƚ� s1 �� s2 �Ƿ����
		cout << "s1 is equal s2";
	s3 = s3.union2(s1, s2);//�� s1 �� s2 �Ľ�
	s4 = s4.incorporate2(s1, s2);//�� s1 �� s2 �Ĳ�
	cout << "\ns1:";
	s1.print();//��� s1 �е�Ԫ��
	cout << "\ns2:";
	s2.print();
	cout << "\ns3:";
	s3.print();
	cout << "\ns4:";
	s4.print();
	system("pause");
	return 0;
}