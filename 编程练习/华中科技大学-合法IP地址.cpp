#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int num = 0;
	cin >> num;
	while (num > 0) {
		int a, b, c, d;
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);//��strtok��ѭ���ַ����鷽����Ҫ��!
		if (a >= 0 && a <= 255 && b >= 0 && b <= 255 &&
			c >= 0 && c <= 255 && d >= 0 && d <= 255)
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;
		num--;
	}
	return 0;
}
/*
��Ŀ����

����һ��ip��ַ�����ж��Ƿ�Ϸ���
��������:
����ĵ�һ�а���һ������n(1<=n<=500)�������������ֵ�IP��ַ�ĸ�����
��������n��ÿ����һ��IP��ַ��IP��ַ����ʽΪa.b.c.d������a��b��c��d����������


�������:
�����ж���������ݣ�����ÿ�����ݣ����IP��ַ�Ϸ������"Yes!�����������"No!����

�Ϸ���IP��ַΪ��
a��b��c��d����0-255��������

��������:
2
255.255.255.255
512.12.2.3

�������:
Yes!
No!*/