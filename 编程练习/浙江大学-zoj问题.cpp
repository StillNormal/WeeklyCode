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

	if (strlen(mid) == 1 && (strlen(left) == strlen(right))) {//规则1和2
		return true;
	}
	else {//规则3
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
对给定的字符串(只包含'z','o','j'三种字符),判断他是否能AC。 是否AC的规则如下： 1. zoj能AC； 2. 若字符串形式为xzojx，则也能AC，其中x可以是N个'o' 或者为空； 3. 若azbjc 能AC，则azbojac也能AC，其中a,b,c为N个'o'或者为空；
输入描述:
输入包含多组测试用例，每行有一个只包含'z','o','j'三种字符的字符串，字符串长度小于等于1000。


输出描述:
对于给定的字符串，如果能AC则请输出字符串“Accepted”，否则请输出“Wrong Answer”。

输入例子:
zoj
ozojo
ozoojoo
oozoojoooo
zooj
ozojo
oooozojo
zojoooo

输出例子:
Accepted
Accepted
Accepted
Accepted
Accepted
Accepted
Wrong Answer
Wrong Answer*/