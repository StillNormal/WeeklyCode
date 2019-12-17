#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
	char* str = new char[400];
	while (cin >> str) {
		int xPos = 0, yPos = 0;
		char* temp = new char[10];
		char* next_token = NULL;
		temp = strtok_s(str, ";", &next_token);//又是不安全的错误，但在平台上还是用strtok，注意第三个参数
		while (temp != NULL) {
			int len = strlen(temp);
			if (len == 0 || len == 1 || len > 3) {//第一种不合法
				temp = strtok_s(NULL, ";", &next_token);//注意遗漏的部分
				continue;
			}
			else if (len == 2) {
				char first = temp[0];
				char second = temp[1];
				if (second < '0' || second > '9') {
					temp = strtok_s(NULL, ";", &next_token);
					continue;
				}
				switch (first) {
				case 'W': yPos += second - '0'; break;
				case 'A': xPos -= second - '0'; break;
				case 'S': yPos -= second - '0'; break;
				case 'D': xPos += second - '0'; break;
				default: temp = strtok_s(NULL, ";", &next_token);  continue;//排除不合法
				}
			}
			else if (len == 3) {
				char first = temp[0];
				char second = temp[1];
				char third = temp[2];
				if (second < '0' || second > '9' || third < '0' || third > '9') {
					temp = strtok_s(NULL, ";", &next_token);
					continue;
				}
				switch (first) {
				case 'W': yPos += (second - '0') * 10 + third - '0'; break;
				case 'A': xPos -= (second - '0') * 10 + third - '0'; break;
				case 'S': yPos -= (second - '0') * 10 + third - '0'; break;
				case 'D': xPos += (second - '0') * 10 + third - '0'; break;
				default: temp = strtok_s(NULL, ";", &next_token); continue;//排除不合法
				}
			}
			temp = strtok_s(NULL, ";", &next_token);
		}
		cout << xPos << "," << yPos << endl;
		delete []temp;
	}
	return 0;
}