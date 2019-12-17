#include <iostream>
using namespace std;

void sort(int a[],int NUM) {//选择排序
	int temp;
	for(int i = 0; i < NUM; i++)
		for(int j = i+1; j < NUM; j++) {
			if(a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
}

void sort2(int a[],int NUM) {//插入排序
	int temp;
	for(int i = 0; i < NUM; i++)
		for(int j = 0; j < i; j++) {
			if(a[i] < a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
}

void sort3(int a[],int NUM) {//冒泡排序
	int temp;
	bool isChange = true;
	while(NUM > 0 && isChange) {
		isChange = false;
		for(int i = 0; i < NUM; i++)
			if(a[i] > a[NUM-1]) {
				temp = a[NUM-1];
				a[NUM-1] = a[i];
				a[i] = temp;
				isChange = true;
			}
		NUM--;
	}
}

void qsort(int a[], int p, int q) {
	if(p >= q)
		return;

	int key = a[q];
	int temp;
	int i, j;

	for(j = p, i = p - 1; j < q; j++) {//分成三段p-i i i-j 最后j与q相等
		if(a[j] < key) {
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	temp = a[i+1];
	a[i+1] = a[q];//这里虽然是key但是千万不能写key!
	a[q] = temp;
	
	qsort(a, p, i);//i+1是key
	qsort(a, i+2, q);
}

void sort4(int a[], int NUM) {//快排
	qsort(a, 0, NUM-1);
} 

int main() {
	int NUM;
	int* a;

	while(scanf("%d",&NUM) != EOF) {//输入NUM 再输入NUM个数
		a = new int[NUM];
		for(int j = 0; j < NUM; j++)
			cin >> a[j];

		sort4(a,NUM);

		for(int i = 0; i < NUM; i++)
			cout << a[i] << " ";
	}

	system("pause");
}