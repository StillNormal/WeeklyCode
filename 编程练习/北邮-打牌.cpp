#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

void qsort(int a[], int p, int q) {
	if (p >= q)
		return;

	int i, j, temp;
	for (i = p - 1, j = p; j < q; j++)
		if (a[j] < a[q]) {
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	temp = a[i + 1];
	a[i + 1] = a[q];
	a[q] = temp;

	qsort(a, p, i);
	qsort(a, i+2, q);
}

int main() {
	char my[100];
	char enemy[100];
	while (scanf("%s", my) != EOF) {
		scanf("%s", enemy);
		int cnt[9];//��Ӧ0-9
		for (int i = 0; i < 9; i++)
			cnt[i] = 0;
		for (int i = 0; i < strlen(my); i++)
			cnt[my[i]-'0'-1]++;
		int len = strlen(enemy);
		bool isWin = false;
		if (len < 5) {
			for (int i = enemy[0] - '0'; i < 9; i++)
				if (cnt[i] >= len) {
					isWin = true;
					break;
				}
		}
		else {
			int begin = enemy[0] - '0';
			bool flag = false;
			for (int i = begin; i <= 9-5; i++) {
				flag = true;
				for (int j = 0; j < 5; j++)
					if (cnt[i + j] == 0) {
						flag = false;
						break;
					}
				if (flag)
					break;
			}
			isWin = flag;
		}

		if (isWin)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
/*
��ֻ��1��9�����������Ѿ��ź������a���Է�����b���ó����ж��������Ƿ��ܹ�ѹ���Է����ơ�  ���򣺳���������5��   [1]һ�� ��4 ��5...9��ѹ�� [2]���� ��44 ��55��66��77��...��99��ѹ�� [3]���� ��444 ������[2] [4]���� ��4444 ������[2] [5]���� ����ֻ��12345 23456 34567 45678 56789���������ı�ǰ��ľ���
��������:
�����ж������ݡ�
ÿ�����������ַ���(�ַ�����С������100)a��b��a�ַ������������ƣ�b�ַ����������ơ�


�������:
ѹ�����YES ����NO��

��������:
12233445566677
33

�������:
YES*/