#pragma warning(disable:4996)//���Ծ���
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int main() {
	int n;//��ƿ��
	while (cin >> n) {
		if (n == 0)
			break;

		int remain_n = n;//ÿ�ֽ�����ʣ�µĿ�ƿ��
		int exchange = 0;//ÿ�ֽ�������ƿ��
		int total = 0;//�ܽ�������ƿ��
		while (remain_n >= 3) {
			exchange = remain_n / 3;
			remain_n = remain_n % 3 + exchange;
			total += exchange;
		}

		if (remain_n == 2)//����ˮ���������
			total++;

		cout << total << endl;
	}
	return 0;
}