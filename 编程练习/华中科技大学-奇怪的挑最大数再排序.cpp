#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

void qsort(int a[], int p, int q) {
	if (p >= q)
		return;

	int i, j, temp;
	for (i = p - 1, j = p; j < q; j++) {
		if (a[j] < a[q]) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i + 1];//这里不要写key
	a[i + 1] = a[q];
	a[q] = temp;

	qsort(a, p, i);
	qsort(a, i + 2, q);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int* a = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, 0, n - 1);
		int max = a[n - 1];
		n--;//奇怪要求 只删最大的一个
		cout << max << endl;
		if (n == 0)
			cout << "-1" << endl;//奇怪要求 为空时要输出-1
		else {
			for (int i = 0; i < n-1; i++)
				cout << a[i] << " ";
			cout << a[n-1] << endl;//奇怪的格式要求
		}
	}
}
/*
输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。
输入描述:
输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。
接下来的一行有N个整数。


输出描述:
可能有多组测试数据，对于每组数据，
第一行输出一个整数，代表N个整数中的最大值，并将此值从数组中去除，将剩下的数进行排序。
第二行将排序的结果输出。

输入例子:
4
1 3 4 2

输出例子:
4
1 2 3*/
