#include<iostream>	
using namespace std;

struct Node {
	char val;
	Node* left;
	Node* right;
};
//�ݹ���Զϵ����ÿ����ӵݹ鴦 Ҳ����һЩ������ʵĹؼ�λ�ÿ���ʱȫ��������Ϣ 
Node* createTree(char pre[], int a, int b, char in[], int c, int d) {//����ǰ���������
	Node* root = new Node;
	root->val = pre[a];
	root->left = NULL;//δ��ʼ����ָ�벻��NULL ����ڱ���ʱ�������
	root->right = NULL;
	if(c == d) //Ҷ�ӽ�� �ݹ��˳�����
		return root;

	int i;
	for(i = c; i <= d; i++)//���Ǽ��� �ұ�Ҫ�Ⱥ�
		if(in[i] == pre[a])//�����һ��Ϊ�� �ٵ�����ȥ��
			break;
	if(i != c) //��������Ϊ��!
		root->left = createTree(pre, a+1, a+i-c, in, c, i-1);//�ø�������Һ��ӽӵݹ鷵�������ĸ����
	if(i != d) //��������Ϊ��!
		root->right = createTree(pre, a+i-c+1, b, in, i+1, d);
	return root;
}
void Postorder(Node* head) {//�������
	if(head == NULL)
		return;
	Postorder(head->left);
	Postorder(head->right);
	cout << head->val;
}
//һ��Ҫ������Ĳ��� ��Ϊ�����������������Ļ���
int main() {
	char pre[20];
	cin >> pre;//�������� fdxeag
	char in[20];
	cin >> in;//xdefag

	Node* head = createTree(pre, 0, strlen(pre)-1, in, 0 , strlen(in)-1);//strlen��ͳ��\0�������ڴ������ַ������±껹Ҫ-1

	Postorder(head);//xedgaf

	system("pause");
}