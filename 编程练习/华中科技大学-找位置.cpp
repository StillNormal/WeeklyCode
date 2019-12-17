#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	char str[100];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		bool* hasCalulate = new bool[len];
		for (int i = 0; i < len; i++)
			hasCalulate[i] = false;

		for (int i = 0; i < len; i++) {
			if (hasCalulate[i])
				continue;

			int num = 0;
			for (int j = i + 1; j < len; j++) //Ϊ��ȡ�㹻��ϢҪ�ȼ��һ��
				if (str[i] == str[j])
					num++;

			if (num != 0) {
				cout << str[i] << ":" << i;
				num--;
				for (int j = i + 1; j < len; j++) {
					if (str[i] == str[j]) {
						cout << "," << str[j] << ":" << j;
						hasCalulate[j] = true;
						num--;
					}
				}
				cout << endl;
			}
		}
	}
}

/*
�Ը�����һ���ַ������ҳ����ظ����ַ�����������λ�ã��磺abcaaAB12ab12 �����a��1��a��4��a��5��a��10��b��2��b��11��1��8��1��12�� 2��9��2��13��
��������:
�������һ������ĸ��������ɵ��ַ������䳤�Ȳ�����100��


�������:
�����ж���������ݣ�����ÿ�����ݣ�
������������ĸ�ʽ���ַ����ֵ�λ�ñ����

1���±��0��ʼ��
2����ͬ����ĸ��һ�б�ʾ������ֹ���λ�á�

��������:
abcaaAB12ab12

�������:
a:0,a:3,a:4,a:9
b:1,b:10
1:7,1:11
2:8,2:12*/