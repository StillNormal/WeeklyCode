#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void qsort(int a[], int p, int q) {
	if(p > q)
		return;
	
	int i, j;
	int temp;
	for(i = p - 1, j = p; j < q; j++)
		if(a[j] < a[q]) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	temp = a[q];
	a[q] = a[i+1];
	a[i+1] = temp;

	qsort(a, p, i);
	qsort(a, i+2, q);
}
struct stu {
	char name[101];
	int age;
	int score;
};

int main() {

	int n;
	while(scanf("%d",&n) != EOF) {
		stu* a = new stu[n];//����ܶ�ѭ����������Դ �ͷſɼ����ڴ�ռ��
		for(int i = 0; i < n; i++)
			cin >> a[i].name >> a[i].age >> a[i].score;
		
		stu temp;//��һ�ְ��ɼ�����
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				if(a[i].score > a[j].score) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
		
		int p = 0;//�ڶ��ֶԳɼ���ͬ�İ��������� ��δͨ��������Ŀû˵��������ͬ�Ļ�Ҫ���������� �����˼·��� Ӧ���ڵ�һ���ŵ�ʱ��һ��Լ������
		bool notChange = true;
		for(int i = 0; i < n-1; i++) {
			notChange = true;
			if(a[i].score != a[i+1].score) {
				for(int j = p; j < i; j++)
					for(int k = j; k < i; k++)
						if(strcmp(a[j].name, a[k].name) < 0) {
							temp = a[i];
							a[i] = a[j];
							a[j] = temp;
						}
				p = i;
				notChange = false;
			}	
		}
		if(notChange)
			for(int j = p; j < n; j++)
				for(int k = j; k < n; k++)
					if(strcmp(a[j].name, a[k].name) < 0) {
						temp = a[j];
						a[j] = a[k];
						a[k] = temp;
					}

		for(int i = 0; i < n; i++) 
			cout << a[i].name << " " << a[i].age << " " << a[i].score << endl;
	}
}