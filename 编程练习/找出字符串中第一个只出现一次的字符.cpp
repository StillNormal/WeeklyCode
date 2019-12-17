#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


int main() {
	char* str = new char[400];
	int cnt[128];//可能的字符数应该不止26+26个
	int pos[128];//对应字符首次出现的位置
	while (cin >> str) {
		int len = strlen(str);
		for (int i = 0; i < 128; i++) {
			cnt[i] = 0;
			pos[i] = 0;
		}
		for (int i = 0; i < len; i++) {
			if (cnt[str[i] - 'a'] == 0)
				pos[str[i] - 'a'] = i;
			cnt[str[i] - 'a']++;
		}

		int firstPos = 9999;
		for (int i = 0; i < 128; i++) {
			if (cnt[i] == 1) {
				if (firstPos > pos[i]) {
					firstPos = pos[i];
				}
			}
		}
		if (firstPos != 9999) {
			cout << str[firstPos] << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
	return 0;
}