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
		stu* a = new stu[n];//这里很多循环都申请资源 释放可减少内存占用
		for(int i = 0; i < n; i++)
			cin >> a[i].name >> a[i].age >> a[i].score;
		
		stu temp;//第一轮按成绩排序
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				if(a[i].score > a[j].score) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
		
		int p = 0;//第二轮对成绩相同的按姓名排序 仍未通过可能题目没说对姓名相同的还要按年龄排序 但这个思路错的 应该在第一次排的时候一次约束条件
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