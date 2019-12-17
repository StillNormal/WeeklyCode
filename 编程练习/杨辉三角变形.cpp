#pragma warning(disable:4996)//忽略警告
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

//两种更好做法 不用递归用循环、找规律

int digui(int row, int col) {//不用递归更好
	if (row == 0 || col < 0 || col >= 2 * row - 1)
		return 0;
	if (col == 0 || col == 2 * row - 2)//两边均为1
		return 1;
	if (row == 1 && col == 0)//第一个数
		return 1;
	//return digui(row - 1, col - 1) + digui(row - 1, col) + digui(row - 1, col + 1);
	return digui(row - 1, col - 2) + digui(row - 1, col - 1) + digui(row - 1, col);//这个三角形并非常规对齐
}

int main() {
	int row;//行从1开始算起
	while (cin >> row) {
		bool flag = false;
		for (int col = 0; col < 2 * row - 1; col++) {
			int val = digui(row, col);
			//cout << val << " ";											  
			if (val % 2 == 0) {
				flag = true;
				cout << col + 1 << endl;
				break;
			}
		}		
		if (!flag)
			cout << -1 << endl;
	}
	return 0;
}