#pragma warning(disable:4996)//���Ծ���
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

//���ָ������� ���õݹ���ѭ�����ҹ���

int digui(int row, int col) {//���õݹ����
	if (row == 0 || col < 0 || col >= 2 * row - 1)
		return 0;
	if (col == 0 || col == 2 * row - 2)//���߾�Ϊ1
		return 1;
	if (row == 1 && col == 0)//��һ����
		return 1;
	//return digui(row - 1, col - 1) + digui(row - 1, col) + digui(row - 1, col + 1);
	return digui(row - 1, col - 2) + digui(row - 1, col - 1) + digui(row - 1, col);//��������β��ǳ������
}

int main() {
	int row;//�д�1��ʼ����
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