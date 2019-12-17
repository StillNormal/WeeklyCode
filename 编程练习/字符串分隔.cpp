#pragma warning(disable:4996)//ºöÂÔ¾¯¸æ
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

void printStr(char* str) {
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (cnt < 8)
			cout << str[i];
		else if (cnt == 8) {
			cout << endl << str[i];
			cnt = 0;
		}
		cnt++;
	}

	while (cnt != 8) {
		cout << "0";
		cnt++;
	}
	cout << endl;
}

int main() {
	char* str = new char[100];
	char* str1 = new char[100];
	while (cin >> str) {
		cin >> str1;
		printStr(str);
		printStr(str1);
	}
	return 0;
}