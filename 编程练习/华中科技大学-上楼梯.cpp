#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int fibo(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return fibo(n - 1) + fibo(n - 2);
}
int main() {
	int n;
	long long fibo[1000];//int会溢出
	fibo[0] = 1;
	fibo[1] = 2;
	for (int i = 2; i < 1000; i++)//用递归会越界
		fibo[i] = fibo[i-1] + fibo[i-2];
	while (scanf("%d", &n) != EOF) {
		cout << fibo[n-1] << endl;
	}
	return 0;
}
/*
N阶楼梯上楼问题：一次可以走两阶或一阶，问有多少种上楼方式。（要求采用非递归）
输入描述:
输入包括一个整数N,(1<=N<90)。


输出描述:
可能有多组测试数据，对于每组数据，
输出当楼梯阶数是N时的上楼方式个数。

输入例子:
4

输出例子:
5*/