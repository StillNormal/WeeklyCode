#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	
	int* buf = new int[n];
	for(int i = 0; i < n; i++) 
		buf[i] = 1;//������

	for(int i = 2; i < n; i++) {
		if(buf[i]) {
			for(int j = 2; j <= n/i; j++)
				buf[i*j] = 0;//���Ϊ������
		}
	}

	for(int i = 2; i < n; i++)
		if(buf[i])
			cout << i << " ";

	system("pause");
}