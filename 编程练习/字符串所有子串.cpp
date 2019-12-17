#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

void substr(char* str, int left, int right, bool isEmpty[]) {
	if (left > right) {//停止条件才是递归终点 此时才能输出!
		for (int i = 0; i <= right; i++)
			if (isEmpty[i])
				cout << str[i];
		cout << endl;
		return;
	}

	isEmpty[left] = false;//以这位打印不打印推出两个分支
	substr(str, left + 1, right, isEmpty);
	isEmpty[left] = true;
	substr(str, left + 1, right, isEmpty);
}
int main() {//除了空串应该有2^n - 1
	char str[100];
	cin >> str;
	bool isEmpty[100];
	for (int i = 0; i < strlen(str); i++)
		isEmpty[i] = true;//该位是否打印
	substr(str, 0, strlen(str)-1, isEmpty);//对字符串或数组这样多数据的递归要用两个下标控制!
	return 0;
}
