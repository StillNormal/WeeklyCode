#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

void qsort(int a[], int p, int q) {
	if (p >= q)
		return;

	int i, j, temp;
	for (i = p - 1, j = p; j < q; j++)
		if (a[j] < a[q]) {
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	temp = a[i + 1];
	a[i + 1] = a[q];
	a[q] = temp;

	qsort(a, p, i);
	qsort(a, i+2, q);
}

int main() {
	char my[100];
	char enemy[100];
	while (scanf("%s", my) != EOF) {
		scanf("%s", enemy);
		int cnt[9];//对应0-9
		for (int i = 0; i < 9; i++)
			cnt[i] = 0;
		for (int i = 0; i < strlen(my); i++)
			cnt[my[i]-'0'-1]++;
		int len = strlen(enemy);
		bool isWin = false;
		if (len < 5) {
			for (int i = enemy[0] - '0'; i < 9; i++)
				if (cnt[i] >= len) {
					isWin = true;
					break;
				}
		}
		else {
			int begin = enemy[0] - '0';
			bool flag = false;
			for (int i = begin; i <= 9-5; i++) {
				flag = true;
				for (int j = 0; j < 5; j++)
					if (cnt[i + j] == 0) {
						flag = false;
						break;
					}
				if (flag)
					break;
			}
			isWin = flag;
		}

		if (isWin)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
/*
牌只有1到9，手里拿着已经排好序的牌a，对方出牌b，用程序判断手中牌是否能够压过对方出牌。  规则：出牌牌型有5种   [1]一张 如4 则5...9可压过 [2]两张 如44 则55，66，77，...，99可压过 [3]三张 如444 规则如[2] [4]四张 如4444 规则如[2] [5]五张 牌型只有12345 23456 34567 45678 56789五个，后面的比前面的均大。
输入描述:
输入有多组数据。
每组输入两个字符串(字符串大小不超过100)a，b。a字符串代表手中牌，b字符串代表处的牌。


输出描述:
压过输出YES 否则NO。

输入例子:
12233445566677
33

输出例子:
YES*/