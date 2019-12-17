#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

bool judge(char* str) {
	int z_num = 0;
	int z_pos = 0;
	int j_num = 0;
	int j_pos = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'z') {
			z_num++;
			z_pos = i;
		}
		if (str[i] == 'j') {
			j_num++;
			j_pos = i;
		}
	}

	if (z_num != 1)
		return false;
	if (j_num != 1) 
		return false;
	if (j_pos < z_pos)
		return false;

	char left[1000];
	int leftI = 0;
	char right[1000];
	int rightI = 0;
	char mid[1000];
	int midI = 0;
	for (int i = 0; i < z_pos; i++) {
		left[leftI] = str[i];
		leftI++;
	}
	left[leftI] = '\0';
	for (int i = z_pos + 1; i < j_pos; i++) {
		mid[midI] = str[i];
		midI++;
	}
	mid[midI] = '\0';
	for (int i = j_pos + 1; i < strlen(str); i++) {
		right[rightI] = str[i];
		rightI++;
	}
	right[rightI] = '\0';

	if (strlen(mid) == 1 && (strlen(left) == strlen(right))) {//����1��2
		return true;
	}
	else {//����3
		char temp[1000];
		strncpy(temp, str, j_pos);
		temp[j_pos-1] = 'j';
		int i = 0;
		if (strlen(right) < strlen(left))
			return false;
		for (; i < strlen(right)-strlen(left); i++)
			temp[j_pos+i] = 'o';
		temp[j_pos + i] = '\0';
		if (judge(temp))
			return true;
		else
			return false;
	}
}
int main() {
	char str[1000];
	while (scanf("%s", str) != EOF) {
		if(judge(str))
			cout << "Accepted" << endl;
		else
			cout << "Wrong Answer" << endl;
	}
}
/*
�Ը������ַ���(ֻ����'z','o','j'�����ַ�),�ж����Ƿ���AC�� �Ƿ�AC�Ĺ������£� 1. zoj��AC�� 2. ���ַ�����ʽΪxzojx����Ҳ��AC������x������N��'o' ����Ϊ�գ� 3. ��azbjc ��AC����azbojacҲ��AC������a,b,cΪN��'o'����Ϊ�գ�
��������:
��������������������ÿ����һ��ֻ����'z','o','j'�����ַ����ַ������ַ�������С�ڵ���1000��


�������:
���ڸ������ַ����������AC��������ַ�����Accepted���������������Wrong Answer����

��������:
zoj
ozojo
ozoojoo
oozoojoooo
zooj
ozojo
oooozojo
zojoooo

�������:
Accepted
Accepted
Accepted
Accepted
Accepted
Accepted
Wrong Answer
Wrong Answer*/