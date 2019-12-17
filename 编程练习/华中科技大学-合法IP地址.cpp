#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int num = 0;
	cin >> num;
	while (num > 0) {
		int a, b, c, d;
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);//比strtok或循环字符数组方法都要好!
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
题目描述

输入一个ip地址串，判断是否合法。
输入描述:
输入的第一行包括一个整数n(1<=n<=500)，代表下面会出现的IP地址的个数。
接下来的n行每行有一个IP地址，IP地址的形式为a.b.c.d，其中a、b、c、d都是整数。


输出描述:
可能有多组测试数据，对于每组数据，如果IP地址合法则输出"Yes!”，否则输出"No!”。

合法的IP地址为：
a、b、c、d都是0-255的整数。

输入例子:
2
255.255.255.255
512.12.2.3

输出例子:
Yes!
No!*/