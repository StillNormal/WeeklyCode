#include <iostream>
using namespace std;

int main() {
	FILE*fp = fopen("21_386811796@qq.com.txt", "r");
	if (fp == NULL)
		return -1;

	long long int a, b;
	int line = 10;
	FILE* fp2 = fopen("out.txt", "w");
	for (int i = 0; i < line - 1; i++) {
		fscanf(fp, "%lld,%lld", &a, &b);
		//printf("%lld\n", a^b);
		fprintf(fp2, "%lld|", a^b);
	}
	fscanf(fp, "%lld,%lld", &a, &b);
	fprintf(fp2, "%lld", a^b);
	fclose(fp);
	fclose(fp2);

	return 0;
}