#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int main() {//自动排版ctrl+k+f或在编辑菜单中找到快捷键
	char a[1000];
	char b[1000];
	char c[1000];
	while (scanf("%s %s", a, b) != EOF) {
		int len1 = strlen(a);
		int len2 = strlen(b);
		int max = len1 > len2 ? len1 : len2;

		for (int i = len1; i < max + 1; i++) //进位最多进一位
			a[i] = '0';
		for (int i = len2; i < max + 1; i++) 
			b[i] = '0';
		for (int i = 0; i < max + 1; i++) 
			c[i] = '0';

		for (int i = 0; i < len1 / 2; i++) {//切记先颠倒一下高位低位 不然太难处理!
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
				c[j + 1] += 1;//下一位的赋值时会盖掉
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
实现一个加法器，使其能够输出a+b的值。
输入描述:
输入包括两个数a和b，其中a和b的位数不超过1000位。


输出描述:
可能有多组测试数据，对于每组数据，
输出a+b的值。

输入例子:
2 6
10000000000000000000 10000000000000000000000000000000

输出例子:
8
10000000000010000000000000000000*/
