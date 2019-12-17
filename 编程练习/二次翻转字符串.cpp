#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void reverse(int start, int end, char* str) {
	if (start == end)
		return;

	char temp;
	for (int i = start; i <= start + (end - start) / 2; i++) { //��ѧ��ϵ
		temp = str[i];
		str[i] = str[end - i + start];
		str[end - i + start] = temp;
	}
	return;
}

//2�η�ת����
int main() {
	char* str = new char[400];
	//while (cin >> str) {//�����ո��ͣ��
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