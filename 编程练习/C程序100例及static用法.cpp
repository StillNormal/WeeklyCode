#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
using namespace std;

void program3() {//��ĳ��
	int M = 10000;
	for(int i=0;i<M;i++) 
		for(int j=0;j<i;j++)
			if(i*i-j*j == 68)//����ȫƽ����δʹ��sqrt
				cout << i*i-268 << " ";
	cout << endl;
}
void program8() {
	int M=9;//99�˷���
	for(int i=1;i<M+1;i++) {
		for(int j=1;j<=i;j++) {
			cout << i << "*" << j << "=" << i*j << " ";
		}
		cout << endl;
	}
}
void program9() { //������������
	for(int i=0;i<8;i++) { 
		for(int j=0;j<8;j++) 
			if((i+j)%2==0) //������� �Ҵ˷������������"EE  "ż����"  EE"Ҫ��
				cout << "EE"; //�ڿ�
			else 
				cout << "  "; 
		cout << endl;
	}
} 
void program14() {//�ֽ�������
	int num;
	cout << "Ҫ�ֽ����" << endl;
	cin >> num;
	cout << num << "=";
	while(true) {
		for(int k=2;k<=num;k++)
			if(num%k==0){
				num /= k;
				cout << k ;
				if(num != 1)//�������һ��*�����
					cout << "*";
				break;
			}
		if(num == 1)
			break;
	}
}
void program54() {//ȡһ������a���Ҷ˿�ʼ��4��7λ
	int a;
	cout << "a:" <<endl;
	cin >> a;
	a = a >> 3;
	a = a & 15;//��~(~0<<4) һ����4λȫΪ1,����ȫΪ0����
	cout << a;
}
void program82() {//ʮ����ת�˽��� �˽���תʮ������ÿλ��10�Ĳ�ͬ�������
	char* a=new char[20];
	cout << "a:" <<endl;
	scanf("%s",a);
	int num;
    num = atoi(a);//�ַ���ת����������
	printf("correct:%o ",num);
	a = itoa(num,a,8);
	printf("myResult:%s \n",a);
}

int main() {
	//program82();
	system("pause");
}
//static���ã�1���أ�����ͬʱ�������ļ�ʱ������δ��staticǰ׺��ȫ�ֱ����ͺ���������ȫ�ֿɼ���
//2 �洢�ھ�̬�������ı������ڳ���ʼ����ʱ�����Ψһ��һ�γ�ʼ����ֻ��ȫ�ֱ�����static�����洢�ھ�̬�洢������static���Կ��Ʊ����Ŀɼ���Χ
//3 static�ĵ�����������Ĭ�ϳ�ʼ��Ϊ0��ȫ�ֱ���Ҳ�߱���һ����
					