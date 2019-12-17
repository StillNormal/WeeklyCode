#pragma warning(disable:4996)//忽略警告
#include <iostream>
#include <string.h>
#include <map>
using namespace std;


//复习map的使用
int main() {
	int n;
	map<int, int> temp;
	while (cin >> n) {
		int key, value;
		map<int, int>::iterator iter;
		for (int i = 0; i < n; i++) {
			cin >> key >> value;
			iter = temp.find(key);
			if (iter != temp.end()) {
				iter->second += value;
			}
			else {
				temp[key] = value;
			}
		}

		for (iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->first << " " << iter->second << endl;
		temp.clear();
	}
	return 0;
}