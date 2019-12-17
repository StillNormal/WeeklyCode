#include<iostream>	
using namespace std;

struct Node {
	int val;
	Node* next;
};

Node* create(int num) {//头插法要带头结点即不存值 不然除第一个外剩下是逆序  而尾插法就无所谓 头结点作用是是处理第一个结点时不需单独讨论
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
Node* create2(int num) {////输入一组测试数据要求是输入顺序 链表不只是存贮结构 应用尾插法
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

Node* reverse(Node* h) {//逆转链表 也可新建一个链表但是头插法读入相当逆转
	if(h == NULL || h->next == NULL)//有头结点就要考虑到h->next->next
		return NULL;
	Node* p = h;
	Node* q = h->next;//q一直是p后面的结点
	Node* temp;
	while(q != NULL) {//关键不是p=p->next这样遍历的 一次要处理三个点
		temp = q->next;//q不为空也杜绝temp找不到的情况
		q->next = p;
		p = q;
		q = temp;
	}		
	h->next = NULL;
	return p;//此时q=NULL 
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
	for(; stepBy2->next != NULL && stepBy2->next->next != NULL; stepBy1 = stepBy1->next, stepBy2 = stepBy2->next->next)//一次跳两个的检查下两个和下一个不为空
		if(stepBy1 == stepBy2)//要么有环检测返回 要么没环走的快的到链尾结束
			return true;
	return false;
}

int findLastK(Node* h, int k) {
	Node* p = h;
	Node* q = h;
	for(int i = 0; i < k; i++) {
		if(q == NULL)
			return -1;//总结点数没有k个
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
void sort(Node* h) {//选择排序 若要nlgn得用归并排序
	int temp;
	for(Node* p = h; p != NULL; p = p->next)
		for(Node* q = p->next; q != NULL; q = q->next)
			if(p->val > q->val) {
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}				
}
void deleteSame(Node* h) {//删除重复的值 也可以先排序再删除
	for(Node* p = h; p != NULL; p = p->next)
		for(Node* q = p; q->next != NULL;) {//q与p指向一样 但处理时q永远用q->next 这样删除时就用q再删q->next
			if(p->val == q->next->val) {
				Node* del = q->next;
				q->next = q->next->next;
				delete del;
			}
			else {
				q = q->next;//发生删除时q指针不能向后移
			}
		}
}
int main() {
	//Node* head = create(6);//创建一个6元素链表
	Node* head2 = create2(6);
	//print(head);
	//print(head2);

	head2 = reverse(head2);//用没头结点的顺序存的尾插链表
	print(head2);

	cout << "是否有环:" << hasLoop(head2) << endl;

	cout << findLastK(head2,10) << " " << findLastK(head2, 3) << endl;

	cout << findMid(head2) << endl;

	sort(head2);
	print(head2);

	deleteSame(head2);
	print(head2);

	system("pause");
}