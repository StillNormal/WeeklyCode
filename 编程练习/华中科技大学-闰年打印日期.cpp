#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int year, day;
	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//月份处理
	int b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (scanf("%d %d", &year, &day) != EOF) {
		bool isLeap;
		if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)//判断条件
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
		cout << year << "-";//格式
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
给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述:
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。


输出描述:
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。

输入例子:
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60

输出例子:
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01*/