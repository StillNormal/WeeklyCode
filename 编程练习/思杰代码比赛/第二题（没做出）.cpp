#include <iostream>
using namespace std;


int main() {
	FILE*fp = fopen("22_386811796@qq.com.txt", "r");
	if (fp == NULL)
		return -1;
	FILE*fp3 = fopen("22_386811796@qq.com.txt", "r");

	int line = 10;
	FILE* fp2 = fopen("out.txt", "w");
	int a;
	char str[120];
	for (int i = 0; i < line - 1; i++) {
		fscanf(fp, "%d", &a);
		fscanf(fp3, "%s", &str);
		int len = strlen(str) + 1;
		int n3_len = len - 32 - 16;
		a = ~a;
		int n1 = a >> (n3_len + 16);
		int n3 = (1 << n3_len) & a;
		int result = n3 % n1;
		cout << len<< endl;
		result = ~result;
		_itoa(result, str, 2);
		bool flag = true;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '1' && flag == true)
				continue;			
			fprintf(fp2, "%c", str[i]);
			flag = false;			
		}
		fprintf(fp2, "|");
	}
	fscanf(fp, "%d", &a);
	fscanf(fp3, "%s", &str);
	int len = strlen(str);
	int n3_len = len - 32 - 16;
	a = ~a;
	int n1 = a >> (n3_len + 16);
	int n3 = (1 << n3_len) & a;
	int result = n3 % n1;
	result = ~result;
	_itoa(result, str, 2);
	bool flag = true;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '1' && flag == true)
			continue;
		fprintf(fp2, "%c", str[i]);
		flag = false;
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}