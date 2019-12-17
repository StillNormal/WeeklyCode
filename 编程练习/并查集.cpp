#include <iostream>
#include <string.h>
using namespace std;

int findRoot(int father[], int n) {
	int root = n;
	while(father[root] != -1) {
		root = father[root];
	}

	int temp;
	while(father[n] != -1) {//�ٱ��������ڵ� ��·��ѹ��
		temp = father[n];
		father[n] = root;
		n = temp;
	}

	return root;
}

int main() {
	int city, road;
	cin >> city >> road;//������ ��·��

	int* father = new int[city+1];//�±��Ӧ �ճ���һ������
	for(int i = 1; i < city+1; i++)
		father[i] = -1;//ֵΪ-1�������ɸ��ڵ�

	int m, n;
	for(int i = 0; i < road; i++) {
		cin >> m >> n;
		father[m] = findRoot(father, n);//Ĭ���Һ�һ�����еĸ��ڵ� ��ǰһ������ָ����
	}
	
	int cnt = 0;
	for(int i = 1; i < city+1; i++)
		if(father[i] == -1)
			cnt++;
	cout << "������·������ " << cnt-1 << endl;
	system("pause");
}