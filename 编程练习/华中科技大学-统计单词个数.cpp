#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	char str[1000];
	while (gets(str) != NULL) {//scanf�����ո�Ϊֹ ��������EOF������NULL
		int len = strlen(str);
		int num = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ') {//�ַ�������˫���ŵ��ַ���
				cout << num << " ";
				num = 0;
			}
			else if (str[i] == '.') {
				cout << num << endl;
			}
			else
				num++;
		}
	}
	return 0;
}
/*
��һ�����򣬶����û�����ģ��ԡ�.����β��һ�����֣�ͳ��һ���ж��ٸ����ʣ����ֱ����ÿ�����ʺ��ж��ٸ��ַ��� ��������һ�������ո�����Ĳ��־�Ϊһ�����ʣ�
��������:
�������1���ַ������ԡ�.���������ַ����а���������ʣ�����֮����һ�������ո������


�������:
�����ж���������ݣ�����ÿ�����ݣ�
����ַ�����ÿ�����ʰ�������ĸ�ĸ�����

��������:
hello how are you.

�������:
5 3 3 3*/