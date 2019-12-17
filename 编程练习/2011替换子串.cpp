#include<iostream>
using namespace std;

int find_str_replace(char str[],const char find_str[],const char replace_str[]) {
	int len = strlen(str);
	int len2 = strlen(find_str);
	int len3 = strlen(replace_str);
	int cnt = 0;

	for(int i = 0; i < len; i++) {
		bool same = true;
		for(int j = 0; j < len2; j++)
			if(find_str[j] != str[j+i]) {
				same = false;
				break;
			}
	
		if(same) {
			for(int j = i; j <= len-len2; j++)
				str[j] = str[j+len2];
			len -= len2;
			for(int j = len; j >= i; j--)
				str[j+len3] = str[j];
			len += len3;
			for(int j = 0; j < len3; j++)
				str[j+i] = replace_str[j];
			cnt++;
			if(-len2 + len3 > 0)//替换的不再检查替换 考虑find-str和replace_str的关系决定i怎么指向
				i = i - len2 + len3;
		}
	}
	cout << str << endl;
	return cnt;
}


int main() {
	char str[40];
	cin >> str;
	const char find_str[20] = "aaa";
	const char replace_str[20] = "aa";

	int num = find_str_replace(str, find_str, replace_str);
	cout << num << endl;
	system("pause");
	return 0;
}