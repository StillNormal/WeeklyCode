#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

void substr(char* str, int left, int right, bool isEmpty[]) {
	if (left > right) {//ֹͣ�������ǵݹ��յ� ��ʱ�������!
		for (int i = 0; i <= right; i++)
			if (isEmpty[i])
				cout << str[i];
		cout << endl;
		return;
	}

	isEmpty[left] = false;//����λ��ӡ����ӡ�Ƴ�������֧
	substr(str, left + 1, right, isEmpty);
	isEmpty[left] = true;
	substr(str, left + 1, right, isEmpty);
}
int main() {//���˿մ�Ӧ����2^n - 1
	char str[100];
	cin >> str;
	bool isEmpty[100];
	for (int i = 0; i < strlen(str); i++)
		isEmpty[i] = true;//��λ�Ƿ��ӡ
	substr(str, 0, strlen(str)-1, isEmpty);//���ַ������������������ݵĵݹ�Ҫ�������±����!
	return 0;
}
