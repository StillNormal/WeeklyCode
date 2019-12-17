#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int year, day;
	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//�·ݴ���
	int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (scanf("%d %d", &year, &day) != EOF) {
		bool isLeap;
		if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)//�ж�����
			isLeap = true;
		else
			isLeap = false;

		int left = day;
		int i = 0;
		while (left > 0) {
			if (isLeap)
				left -= b[i];
			else
				left -= a[i];
			i++;
		}
		cout << year << "-";//��ʽ
		if (i < 10)
			cout << "0" << i << "-";
		else
			cout << i << "-";
		if (isLeap)
			left += b[i - 1];
		else
			left += a[i - 1];
		if (left < 10)
			cout << "0" << left << endl;
		else
			cout << left << endl;
	}
}
/*
�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
��������:
���������������y(1<=y<=3000)��n(1<=n<=366)��


�������:
�����ж���������ݣ�����ÿ�����ݣ�
�� yyyy-mm-dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������

��������:
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60

�������:
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01*/