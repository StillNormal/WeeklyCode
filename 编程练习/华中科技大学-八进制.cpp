#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;
	int save[10000];
	while (scanf("%d", &n) != EOF) {
		int index = 0;//����ʼ���λ��!
		while (n != 0) {
			save[index] = n % 8;
			index++;
			n /= 8;
		}
		for (int i = index - 1; i >= 0; i--)
			cout << save[i];
		cout << endl;
	}
	return 0;
}
/*
����һ������������ת���ɰ˽����������
��������:
�������һ������N(0<=N<=100000)��


�������:
�����ж���������ݣ�����ÿ�����ݣ�
���N�İ˽��Ʊ�ʾ����

��������:
7
8
9

�������:
7
10
11*/