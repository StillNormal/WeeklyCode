#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;
	int save[10000];
	while (scanf("%d", &n) != EOF) {
		int index = 0;//这句初始语句位置!
		while (n != 0) {
			save[index] = n % 8;
			index++;
			n /= 8;
		}
		for (int i = index - 1; i >= 0; i--)
			cout << save[i];
		cout << endl;
	}
	return 0;
}
/*
输入一个整数，将其转换成八进制数输出。
输入描述:
输入包括一个整数N(0<=N<=100000)。


输出描述:
可能有多组测试数据，对于每组数据，
输出N的八进制表示数。

输入例子:
7
8
9

输出例子:
7
10
11*/