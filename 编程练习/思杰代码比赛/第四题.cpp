#include <iostream>
using namespace std;


int main() {
	FILE*fp = fopen("24_386811796@qq.com.txt", "r");
	if (fp == NULL)
		return -1;


	int line = 10;
	FILE* fp2 = fopen("out.txt", "w");
	for (int i = 0; i < line - 1; i++) {
		int a[30];
		int j;
		for (j = 0; j < 29; j++)//读入
			fscanf(fp, "%d,", &a[j]);
		fscanf(fp, "%d", &a[j]);

		int result[30];//动态规划
		result[0] = 0;
		for (int j = 1; j < 30; j++) {
			int min = 9999;
			for (int k = 0; k < j; k++) {
				if (a[k] + k >= j) {
					if (min > result[k] + 1)
						min = result[k] + 1;
				}
			}
			result[j] = min;
		}
		fprintf(fp2, "%d|", result[29]);//下标-1
	}
	int a[30];
	int j;
	for (j = 0; j < 29; j++)
		fscanf(fp, "%d,", &a[j]);
	fscanf(fp, "%d", &a[j]);

	int result[30];
	result[0] = 0;
	for (int j = 1; j < 30; j++) {
		int min = 9999;
		for (int k = 0; k < j; k++) {
			if (a[k] + k >= j) {
				if (min > result[k] + 1)
					min = result[k] + 1;
			}
		}
		result[j] = min;
	}
	fprintf(fp2, "%d", result[29]);

	fclose(fp);
	fclose(fp2);
	return 0;
}