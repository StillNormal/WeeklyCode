#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {//�Զ��Ű�ctrl+k+f���ڱ༭�˵����ҵ���ݼ�
	char a[1000];
	char b[1000];
	char c[1000];
	while (scanf("%s %s", a, b) != EOF) {
		int len1 = strlen(a);
		int len2 = strlen(b);
		int max = len1 > len2 ? len1 : len2;

		for (int i = len1; i < max + 1; i++) //��λ����һλ
			a[i] = '0';
		for (int i = len2; i < max + 1; i++) 
			b[i] = '0';
		for (int i = 0; i < max + 1; i++) 
			c[i] = '0';

		for (int i = 0; i < len1 / 2; i++) {//�м��ȵߵ�һ�¸�λ��λ ��Ȼ̫�Ѵ���!
			char temp = a[i];
			a[i] = a[len1-i-1];
			a[len1-i-1] = temp;
		}		
		for (int i = 0; i < len2 / 2; i++) {
			char temp = b[i];
			b[i] = b[len2-i-1];
			b[len2-i-1] = temp;
		}

		int min = len1 < len2 ? len1 : len2;

		for (int i = 0; i < max; i++) 
			c[i] = a[i] - '0' + b[i] - '0' + '0';
		for (int j = 0; j < max; j++)
			if (c[j] - '0' >= 10) {
				c[j] -= 10;
				c[j + 1] += 1;//��һλ�ĸ�ֵʱ��ǵ�
			}

		int j;
		if (c[max] != '0')
			j = max;
		else
			j = max - 1;
		for (; j >= 0; j--) 
			cout << c[j]-'0';
		cout << endl;
	}
	return 0;
}
/*
ʵ��һ���ӷ�����ʹ���ܹ����a+b��ֵ��
��������:
�������������a��b������a��b��λ��������1000λ��


�������:
�����ж���������ݣ�����ÿ�����ݣ�
���a+b��ֵ��

��������:
2 6
10000000000000000000 10000000000000000000000000000000

�������:
8
10000000000010000000000000000000*/
