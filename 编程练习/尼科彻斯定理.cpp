#include <iostream>
#include <string>
using namespace std;


int main() {
	int m;
	while (cin >> m) {
		int val = m * m * m;
		int center = val / m;
		if (m % 2 == 0) {//ż��
			int begin = center - 2 * (m / 2) + 1;//��ѧ��ϵ
			int i = 0;
			for (; i < m - 1; i++) {//�����ʽҪ��
				cout << begin + 2 * i << "+";				
			}			
			cout << begin + 2 * i;
		}
		else {//����
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