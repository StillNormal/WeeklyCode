#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	while (n != 0) {
		if (n == 1) {//只有一个元素特殊考虑
			cin >> n;
			cout << n << " " << n << " " << n << endl;
			scanf("%d", &n);
			continue;
		}
		int a[10000];
		int isNeg = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < 0)
				isNeg++;
		}
		if (isNeg == n) {//若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。
			cout << "0 " << a[0] << " " << a[n-1] << endl;
			scanf("%d", &n);
			continue;
		}
		int b[10000];
		b[0] = a[0];
		int first[10000];//记录该序列first位置 这样还能解决最小i的问题
		first[0] = 0;
		for (int i = 1; i < n; i++) {//动态规划
			b[i] = a[i] > a[i] + b[i - 1] ? a[i] : a[i] + b[i - 1];
			first[i] = a[i] > a[i] + b[i - 1] ? i : first[i-1];
		}

		int max = a[0];
		int last = 0;
		for (int i = 0; i < n; i++) 
			if (max < b[i]) {//考虑0 如果最大连续子序列不唯一，则输出序号i和j最小的那个 这里max不取=处理j
				max = b[i];
				last = i;
			}
		/*这方法各种问题
		int first = -1;
		for (int i = last - 1; i > 0; i--)//a[0] = b[0]本来就成立
			if (b[i] == a[i]) {//不break是要找最小的i
				first = i;
			}
		if (first == -1)//序列只有一个元素的情况
			first = last;
			*/
		cout << max << " " << a[first[last]] << " " << a[last] << endl;
		scanf("%d", &n);
	}
	return 0;
}
/*
给定K个整数的序列{ N1, N2, ..., NK }，其任意连续子序列可表示为{ Ni, Ni+1, ..., Nj }，其中 1 <= i <= j <= K。最大连续子序列是所有连续子序列中元素和最大的一个，例如给定序列{ -2, 11, -4, 13, -5, -2 }，其最大连续子序列为{ 11, -4, 13 }，最大和为20。现在增加一个要求，即还需要输出该子序列的第一个和最后一个元素。
输入描述:
测试输入包含若干测试用例，每个测试用例占2行，第1行给出正整数K( K< 10000 )，第2行给出K个整数，中间用空格分隔。当K为0时，输入结束，该用例不被处理。


输出描述:
对每个测试用例，在1行里输出最大和、最大连续子序列的第一个和最后一个元素，中间用空格分隔。如果最大连续子序列不唯一，则输出序号i和j最小的那个（如输入样例的第2、3组）。若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。

输入例子:
6
-2 11 -4 13 -5 -2
10
-10 1 2 3 4 -5 -23 3 7 -21
6
5 -8 3 2 5 0
1
10
3
-1 -5 -2
3
-1 0 -2
0

输出例子:
20 11 13
10 1 4
10 3 5
10 10 10
0 -1 -2
0 0 0*/