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
			for (int j = i + 1; j < len; j++) //为获取足够信息要先检查一遍
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
对给定的一个字符串，找出有重复的字符，并给出其位置，如：abcaaAB12ab12 输出：a，1；a，4；a，5；a，10，b，2；b，11，1，8；1，12， 2，9；2，13。
输入描述:
输入包括一个由字母和数字组成的字符串，其长度不超过100。


输出描述:
可能有多组测试数据，对于每组数据，
按照样例输出的格式将字符出现的位置标出。

1、下标从0开始。
2、相同的字母在一行表示出其出现过的位置。

输入例子:
abcaaAB12ab12

输出例子:
a:0,a:3,a:4,a:9
b:1,b:10
1:7,1:11
2:8,2:12*/