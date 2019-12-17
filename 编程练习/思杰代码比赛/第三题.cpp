#include <iostream>
using namespace std;

long long int save[50];//预先算好斐波那契数列

void cal_fibo() {
	save[0] = 1;
	save[1] = 2;
	for (int i = 2; i < 50; i++)
		save[i] = save[i - 1] + save[i - 2];
	return;
}

int main() {
	FILE*fp = fopen("23_386811796@qq.com.txt", "r");
	if (fp == NULL)
		return -1;

	cal_fibo();

	int a;
	int line = 10;
	FILE* fp2 = fopen("out.txt", "w");
	for (int i = 0; i < line - 1; i++) {
		fscanf(fp, "%d", &a);
		fprintf(fp2, "%lld|", save[a - 1]);//下标-1
	}
	fscanf(fp, "%d", &a);
	fprintf(fp2, "%lld", save[a - 1]);
	fclose(fp);
	fclose(fp2);

	return 0;
}