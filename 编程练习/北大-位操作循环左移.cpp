#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

int main() {//��һ�ּ򵥵ķ����Ƿֽ�ÿλ��char�����У���������
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned short a, b;
		cin >> a >> b;

		bool flag = false;
		for (int j = 0; j < 16; j++) {//������������16λ���� ע����unsigned short��	
			unsigned short highest = 0x8000;
			highest = a & highest;
			highest = highest >> 15;
			a = a << 1;
			a = a | highest;
			if (a == b) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "NO" << endl;
	}
	return 0;
}
/*
��������������65535�ķǸ��������ж�����һ����16λ�����Ʊ�ʾ��ʽ���Ƿ�������һ����16λ�����Ʊ�ʾ��ʽ����ѭ����������λ���õ��� ѭ�����ƺ���ͨ���Ƶ��������ڣ�����ߵ���һλ����ѭ������һλ��ͻᱻ�Ƶ����ұ�ȥ�����磺 1011 0000 0000 0001 ����ѭ������һλ�󣬱�� 0110 0000 0000 0011, ����ѭ������2λ������ 1100 0000 0000 0110
��������:
��һ���Ǹ�����n, 0 < n < 300000,��ʾ���滹��n������
������n�У�ÿ��������������65535�ķǸ�����


�������:
����ÿһ�е��������������һ�У�����ΪYES��NO

��������:
4
2 4
9 18
45057 49158
7 12*/