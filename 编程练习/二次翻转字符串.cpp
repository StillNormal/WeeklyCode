#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void reverse(int start, int end, char* str) {
	if (start == end)
		return;

	char temp;
	for (int i = start; i <= start + (end - start) / 2; i++) { //数学关系
		temp = str[i];
		str[i] = str[end - i + start];
		str[end - i + start] = temp;
	}
	return;
}

//2次翻转方法
int main() {
	char* str = new char[400];
	//while (cin >> str) {//读到空格就停了
	while (gets_s(str, 400)) {
		int len = strlen(str);
		reverse(0, len - 1, str);
		int i = 0;
		for (int j = 0; j <= len; j++) {
			if (str[j] == ' ') {
				reverse(i, j - 1, str);
				j++;
				i = j;
			}
		}
		cout << str << endl;
	}
}