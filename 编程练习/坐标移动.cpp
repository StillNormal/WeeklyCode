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
		temp = strtok_s(str, ";", &next_token);//���ǲ���ȫ�Ĵ��󣬵���ƽ̨�ϻ�����strtok��ע�����������
		while (temp != NULL) {
			int len = strlen(temp);
			if (len == 0 || len == 1 || len > 3) {//��һ�ֲ��Ϸ�
				temp = strtok_s(NULL, ";", &next_token);//ע����©�Ĳ���
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
				default: temp = strtok_s(NULL, ";", &next_token);  continue;//�ų����Ϸ�
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
				default: temp = strtok_s(NULL, ";", &next_token); continue;//�ų����Ϸ�
				}
			}
			temp = strtok_s(NULL, ";", &next_token);
		}
		cout << xPos << "," << yPos << endl;
		delete []temp;
	}
	return 0;
}