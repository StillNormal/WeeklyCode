#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)
bool canPlace(int pos, int colum[], int row) {
	for (int i = 0; i < row; i++)
		if (colum[i] == pos || 
			(abs(i - row) == abs(colum[i] - pos)))//�Ѿ���ͬ�� �����ų�ͬ�к�б�� �����ʱrow,pos
			return false;
	return true;
}
int main() {
	int colum[8];//��¼�ʺ�������� �±����к�
	for (int i = 0; i < 8; i++)
		colum[i] = -1;//��Ϊ�Ǵ�+1��ʼ�� ���������ʼ������0
	int count = 0;//��¼�ܵĽ���
	int row = 0;
	while (row < 8) {
		bool hasPlace = false;
		for (int i = colum[row]+1; i < 8; i++)
			if (canPlace(i, colum, row)) {
				colum[row] = i;
				row++; 
				hasPlace = true;
				break;
			}
		if (!hasPlace) {			
			for (int j = row; j < 8; j++)//���״̬������һ��
				colum[j] = -1;
			row--;
		}
		if (row == 8) {//�ҵ�һ�����
			count++;
			row--;
		}
		if (row == -1) {//�ҵ����һ��������˻�row=-1����ѭ����ֹ����
			break;
		}
	}
	cout << count;
	system("pause");
	return 0;
}
