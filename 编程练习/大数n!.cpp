#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int result[1000];
	for(int i = 0; i < 1000; i++)	
		result[i] = 0;
	result[0] = 1;//��ֵΪ1
	int len = 1;//����Ϊ1

	int n;
	cin >> n;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < len; j++) 
			result[j] *= i;
		for(int j = 0; j < len-1; j++) {
			if(result[j] >= 10) {//��whileѭ����λ��
				result[j+1] += (result[j]/10);//�ͺ�һ���˳���ܷ�
				result[j] %= 10;
			}
		}
		if(result[len-1] >= 10) {//���λ��λʱ���ȼ�һ
			result[len] += (result[len-1]/10);
			result[len-1] %= 10;
			len++;
		}
	}
	
	for(int i = len-1; i >= 0; i--)//�Ӹ�λ����λ���
		cout << result[i];

	system("pause");
}