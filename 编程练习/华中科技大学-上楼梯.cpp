#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

int fibo(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return fibo(n - 1) + fibo(n - 2);
}
int main() {
	int n;
	long long fibo[1000];//int�����
	fibo[0] = 1;
	fibo[1] = 2;
	for (int i = 2; i < 1000; i++)//�õݹ��Խ��
		fibo[i] = fibo[i-1] + fibo[i-2];
	while (scanf("%d", &n) != EOF) {
		cout << fibo[n-1] << endl;
	}
	return 0;
}
/*
N��¥����¥���⣺һ�ο��������׻�һ�ף����ж�������¥��ʽ����Ҫ����÷ǵݹ飩
��������:
�������һ������N,(1<=N<90)��


�������:
�����ж���������ݣ�����ÿ�����ݣ�
�����¥�ݽ�����Nʱ����¥��ʽ������

��������:
4

�������:
5*/