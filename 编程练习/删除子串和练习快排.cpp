#include <iostream>
#include <string.h>
using namespace std;

void qsort(int a[], int p, int q) {//Ϊ��ϰ������д�Ŀ��� ��֪����ȷ
	if(p > q)
		return;
	
	int temp;
	int i,j;
	for(i = p - 1, j = p; j < q; j++) {
		if(a[i] < a[q]) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;//i++λ�ô���
		}
	}
	//©��keyԪ�غ�i+1���midλ�õĽ���

	qsort(a, p, i);
	qsort(a, i+2, q);
}

int find(char str[],char sub[]) {
	int j;//�ִ�λ��
	int tempi;//���濪ʼ�ҵ��±�
	for(int i = 0; i < 100; i++) {
		tempi = i;
		j = 0;
		while(str[tempi] == sub[j] && j < strlen(sub)) {
			tempi++;
			j++;
		}
		if(j == strlen(sub)) 
			return i;//�����ҵ���һ���ִ����±�
	}
	return -1;//û�ҵ�
}

int main() {
	char sub[20];
	cin >> sub;
	char str[100];
	cin >> str;
	
	int len1 = strlen(sub);
	int len2 = strlen(str);
	
	int temp = find(str, sub);
	while(temp != -1) {
		for(int i = temp; i < len2; i++)		
			str[i] = str[i+len1];
		len2 -= len1;
		temp = find(str, sub);
	}

	cout << str;
	system("pause");
}