#pragma warning(disable:4996)//���Ծ���
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char* str = new char[400];
	int subStrLen;
	while (cin >> str >> subStrLen) {
		if (strlen(str) <= subStrLen) {//�����������
			cout << str << endl;
			continue;
		}
		int len = strlen(str);
		char* subStr = new char[subStrLen + 1];
		subStr[subStrLen] = '\0';
		int maxCGnum = 0;
		char* saveMaxStr = new char[subStrLen + 1];
		saveMaxStr[subStrLen] = '\0';
		for (int i = 0; i < len - subStrLen; i++) {
			strncpy(subStr, str + i, subStrLen);
			int CGnum = 0;
			for (int i = 0; i < subStrLen; i++) {
				if (subStr[i] == 'C' || subStr[i] == 'G')
					CGnum++;
			}
			if (CGnum > maxCGnum) {//û�е���
				maxCGnum = CGnum;
				strcpy(saveMaxStr, subStr);//Ӧ�ò����õ��ڸ�ֵ
				//saveMaxStr = subStr;
			}
		}
		cout << saveMaxStr << endl;
	}
	return 0;
}