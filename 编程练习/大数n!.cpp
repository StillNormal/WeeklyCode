#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int result[1000];
	for(int i = 0; i < 1000; i++)	
		result[i] = 0;
	result[0] = 1;//初值为1
	int len = 1;//初长为1

	int n;
	cin >> n;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < len; j++) 
			result[j] *= i;
		for(int j = 0; j < len-1; j++) {
			if(result[j] >= 10) {//比while循环进位快
				result[j+1] += (result[j]/10);//和后一句的顺序不能反
				result[j] %= 10;
			}
		}
		if(result[len-1] >= 10) {//最高位进位时长度加一
			result[len] += (result[len-1]/10);
			result[len-1] %= 10;
			len++;
		}
	}
	
	for(int i = len-1; i >= 0; i--)//从高位往低位输出
		cout << result[i];

	system("pause");
}