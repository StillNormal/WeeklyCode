#include <iostream>
#include <string>
using namespace std;


int main() {
	int m;
	while (cin >> m) {
		int val = m * m * m;
		int center = val / m;
		if (m % 2 == 0) {//偶数
			int begin = center - 2 * (m / 2) + 1;//数学关系
			int i = 0;
			for (; i < m - 1; i++) {//输出格式要求
				cout << begin + 2 * i << "+";				
			}			
			cout << begin + 2 * i;
		}
		else {//奇数
			int begin = center - 2 * (m - 1) / 2;
			int i = 0;
			for (; i < m - 1; i++) {
				cout << begin + 2 * i << "+";
			}
			cout << begin + 2 * i;
		}
		cout << endl;
	}
	return 0;
}