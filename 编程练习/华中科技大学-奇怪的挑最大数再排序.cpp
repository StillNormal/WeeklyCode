#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

void qsort(int a[], int p, int q) {
	if (p >= q)
		return;

	int i, j, temp;
	for (i = p - 1, j = p; j < q; j++) {
		if (a[j] < a[q]) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i + 1];//���ﲻҪдkey
	a[i + 1] = a[q];
	a[q] = temp;

	qsort(a, p, i);
	qsort(a, i + 2, q);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int* a = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, 0, n - 1);
		int max = a[n - 1];
		n--;//���Ҫ�� ֻɾ����һ��
		cout << max << endl;
		if (n == 0)
			cout << "-1" << endl;//���Ҫ�� Ϊ��ʱҪ���-1
		else {
			for (int i = 0; i < n-1; i++)
				cout << a[i] << " ";
			cout << a[n-1] << endl;//��ֵĸ�ʽҪ��
		}
	}
}
/*
����һϵ������������������������������ʣ�µ�����������
��������:
�����һ�а���1������N��1<=N<=1000�������������ݵĸ�����
��������һ����N��������


�������:
�����ж���������ݣ�����ÿ�����ݣ�
��һ�����һ������������N�������е����ֵ��������ֵ��������ȥ������ʣ�µ�����������
�ڶ��н�����Ľ�������

��������:
4
1 3 4 2

�������:
4
1 2 3*/
