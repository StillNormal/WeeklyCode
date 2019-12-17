#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)


int main() {
	char str[1000];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		int side = len;
		int bottom;
		for (; side > 0; side--) {
			bottom = len + 2 - 2 * side;
			if (bottom >= side)
				break;
		}
		for (int i = 0; i < side - 1; i++) {
			cout << str[i];
			for (int j = 0; j < bottom - 2; j++)
				cout << " ";
			cout << str[len - i - 1] << endl;
		}
		for (int i = 0; i < bottom; i++)//最后一行
			cout << str[side + i - 1];
		cout << endl;
	}
	return 0;
}
/*
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as: h  d e  l l  r lowo That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
输入描述:
There are multiple test cases.Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.


输出描述:
For each test case, print the input string in the shape of U as specified in the description.

输入例子:
helloworld!
www.nowcoder.com

输出例子:
h   !
e   d
l   l
lowor
w    m
w    o
w    c
.    .
n    r
owcode*/