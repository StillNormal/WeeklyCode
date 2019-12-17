#include <iostream>
#include <string.h>
using namespace std;

struct Node {//��ׯ�� ��ׯ�� ����
	int city1;
	int city2;
	int len;
};

void qsort(Node s[], int p, int q) {
	if(p > q) 
		return;
	
	int i, j;
	Node temp;//��ͬ�ṹ���Ӧ��ֵ
	for(i = p - 1, j = p; j < q; j++) 
		if(s[j].len < s[q].len) {//ѡ���ұߵ�Ԫ��Ϊkey
			i++;
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	temp = s[i+1];
	s[i+1] = s[q];
	s[q] = temp;

	qsort(s, p, i);
	qsort(s, i+2, q);
}

int main() {
	int num;
	cin >> num;//��ׯ��
	
	Node* save = new Node[num*(num-1)/2];
	for(int i = 0; i < num*(num-1)/2; i++)
		cin >> save[i].city1 >> save[i].city2 >> save[i].len;

	qsort(save, 0, num*(num-1)/2-1);
	
	int cnt = 0;
	bool* isIn = new bool[num+1];//�±��Ӧ �ճ���һ������
	for(int i = 1; i < num+1; i++) 
		isIn[i] = false;//һ��ʼ�������޺õļ�����

	for(int i = 0; i < num*(num-1)/2; i++) {
		if(!isIn[save[i].city1] || !isIn[save[i].city2]) {//����ׯ��ֻҪ��һ�����ټ�����
			cnt += save[i].len;
			isIn[save[i].city1] = true;
			isIn[save[i].city2] = true;
		}

		bool ok = true;
		for(int i = 1; i < num+1; i++)
			if(!isIn[i]) {
				ok = false;
				break;
			}
		if(ok)//���ж��ڼ����� ����������
			break;
	}

	cout << "���·��Ϊ " << cnt << endl;
	system("pause");
}