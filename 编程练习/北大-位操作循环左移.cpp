#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

int main() {//另一种简单的方法是分解每位到char数组中，再做处理
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned short a, b;
		cin >> a >> b;

		bool flag = false;
		for (int j = 0; j < 16; j++) {//这里两个都是16位的数 注意用unsigned short存	
			unsigned short highest = 0x8000;
			highest = a & highest;
			highest = highest >> 15;
			a = a << 1;
			a = a | highest;
			if (a == b) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "NO" << endl;
	}
	return 0;
}
/*
给出两个不大于65535的非负整数，判断其中一个的16位二进制表示形式，是否能由另一个的16位二进制表示形式经过循环左移若干位而得到。 循环左移和普通左移的区别在于：最左边的那一位经过循环左移一位后就会被移到最右边去。比如： 1011 0000 0000 0001 经过循环左移一位后，变成 0110 0000 0000 0011, 若是循环左移2位，则变成 1100 0000 0000 0110
输入描述:
第一行是个整数n, 0 < n < 300000,表示后面还有n行数据
后面是n行，每行有两个不大于65535的非负整数


输出描述:
对于每一行的两个整数，输出一行，内容为YES或NO

输入例子:
4
2 4
9 18
45057 49158
7 12*/