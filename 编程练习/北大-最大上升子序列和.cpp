#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main() {
	int n;
	int a[1000];
	int max;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int state[1000];//到某一位时最大子序列的和
		state[0] = a[0];
		for (int i = 1; i < n; i++) {
			state[i] = a[i];
			for (int j = 0; j < i; j++)
				if (a[j] < a[i] && state[i] < a[i] + state[j]) {
					state[i] = a[i] + state[j];
				}
		}

		max = -1;
		for (int i = 0; i < n; i++)
			if (max < state[i])
				max = state[i];
		cout << max << endl;
	}
	return 0;
}
/*
贪心算法：
所作出的每一步贪心决策都是无法改变的，下一步的最优解是由上一步的最优解直接推导出来的；
也就是说，上一步的最优解就是组成下一步最优解的一部分，所以贪心算法是不会保留上一步之前得出的解的

动态规划算法：
全局的最优解是包含某个局部最优解的，但这个局部最优解不一定就是上一步的最优解，所以动态规划算法是需要保留所有之前所得出的最优解的；
也就是说，已经得到的所有最优解中，包含了推导出下一步最优解的信息，不同于贪心的是我们并不确定到底是那一个，所以计算过程中是需要保留所有得出的子最优解的
*/