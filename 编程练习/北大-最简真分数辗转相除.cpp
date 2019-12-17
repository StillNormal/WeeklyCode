#pragma warning(disable:4996)
#include <iostream>
using namespace std;

bool find(int a, int b) {
	int min = a < b ? a : b;
	for (int i = 2; i <= min; i++)
		if (a%i == 0 && b%i == 0)
			return true;
	return false;
}

bool gcd(int a, int b) {//非递归辗转相除 不需要考虑两数大小关系 比上面的暴力法快
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;//关键
		c = a % b;
	}
	if (b == 1)//关键 最后得到的最大公约数是1说明互质
		return false;
	else
		return true;
}
int main() {
	int n;
	int a[600];
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j])
					continue;
				if (!gcd(a[i], a[j]))
					cnt++;
			}
		cout << cnt << endl;
		cin >> n;

	}
	return 0;
}