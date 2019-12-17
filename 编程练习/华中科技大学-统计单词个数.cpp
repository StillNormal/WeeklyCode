#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	char str[1000];
	while (gets(str) != NULL) {//scanf读到空格为止 且这里是EOF而不是NULL
		int len = strlen(str);
		int num = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ') {//字符而不是双引号的字符串
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
编一个程序，读入用户输入的，以“.”结尾的一行文字，统计一共有多少个单词，并分别输出每个单词含有多少个字符。 （凡是以一个或多个空格隔开的部分就为一个单词）
输入描述:
输入包括1行字符串，以“.”结束，字符串中包含多个单词，单词之间以一个或多个空格隔开。


输出描述:
可能有多组测试数据，对于每组数据，
输出字符串中每个单词包含的字母的个数。

输入例子:
hello how are you.

输出例子:
5 3 3 3*/