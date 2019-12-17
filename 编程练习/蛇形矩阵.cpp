#include <iostream>
using namespace std;

//找规律
int main() {
	int n;
	while (cin >> n) {
		int row_begin = 1;
		int row_incre_base = 2;//横向增长基值
		int col_incre_base = 1;

		while (n > 0) {
			cout << row_begin;
			int temp = row_begin;
			for (int i = row_incre_base; i < row_incre_base + n - 1; i++) {
				temp += i;
				cout << " " << temp;
			}
			cout << endl;
			row_incre_base++;
			row_begin += col_incre_base;
			col_incre_base++;
			n--;
		}
	}
}