#pragma warning(disable:4996)//忽略警告
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int main() {
	int n;//空瓶子
	while (cin >> n) {
		if (n == 0)
			break;

		int remain_n = n;//每轮交换后剩下的空瓶子
		int exchange = 0;//每轮交换到的瓶子
		int total = 0;//总交换到的瓶子
		while (remain_n >= 3) {
			exchange = remain_n / 3;
			remain_n = remain_n % 3 + exchange;
			total += exchange;
		}

		if (remain_n == 2)//借汽水的神奇规则
			total++;

		cout << total << endl;
	}
	return 0;
}