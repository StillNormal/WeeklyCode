#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int a[150][150];
	while (cin >> s1 >> s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		//��ʼ��
		for (int i = 0; i < len1 + 1; i++)
			for (int j = 0; j < len2 + 1; j++)
				a[i][j] = 0;
		for (int i = 0; i < len1 + 1; i++) {
			a[i][0] = i;
		}
		for (int j = 0; j < len2 + 1; j++) {
			a[0][j] = j;
		}
        //��̬�滮
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) {
					a[i + 1][j + 1] = a[i][j];
				}
				else {
					int min = (a[i + 1][j] + 1 >= a[i][j + 1] + 1) ? a[i][j + 1] + 1 : a[i + 1][j] + 1;
					min = (min >= a[i][j] + 1) ? a[i][j] + 1 : min;
					a[i + 1][j + 1] = min;
				}
			}
		}
        //����ĸ�ʽҪ������ķ���
		int val = a[len1][len2] + 1;
		cout << "1/" << val << endl;
	}
	return 0;
}