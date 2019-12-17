#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
using namespace std;

void program3() {//求某数
	int M = 10000;
	for(int i=0;i<M;i++) 
		for(int j=0;j<i;j++)
			if(i*i-j*j == 68)//对完全平方数未使用sqrt
				cout << i*i-268 << " ";
	cout << endl;
}
void program8() {
	int M=9;//99乘法表
	for(int i=1;i<M+1;i++) {
		for(int j=1;j<=i;j++) {
			cout << i << "*" << j << "=" << i*j << " ";
		}
		cout << endl;
	}
}
void program9() { //国际象棋棋盘
	for(int i=0;i<8;i++) { 
		for(int j=0;j<8;j++) 
			if((i+j)%2==0) //核心语句 且此法比奇数行输出"EE  "偶数行"  EE"要好
				cout << "EE"; //黑块
			else 
				cout << "  "; 
		cout << endl;
	}
} 
void program14() {//分解质因数
	int num;
	cout << "要分解的数" << endl;
	cin >> num;
	cout << num << "=";
	while(true) {
		for(int k=2;k<=num;k++)
			if(num%k==0){
				num /= k;
				cout << k ;
				if(num != 1)//控制最后一个*的输出
					cout << "*";
				break;
			}
		if(num == 1)
			break;
	}
}
void program54() {//取一个整数a从右端开始的4～7位
	int a;
	cout << "a:" <<endl;
	cin >> a;
	a = a >> 3;
	a = a & 15;//或~(~0<<4) 一个低4位全为1,其余全为0的数
	cout << a;
}
void program82() {//十进制转八进制 八进制转十进制是每位乘10的不同幂再相加
	char* a=new char[20];
	cout << "a:" <<endl;
	scanf("%s",a);
	int num;
    num = atoi(a);//字符串转换成整型数
	printf("correct:%o ",num);
	a = itoa(num,a,8);
	printf("myResult:%s \n",a);
}

int main() {
	//program82();
	system("pause");
}
//static作用：1隐藏，我们同时编译多个文件时，所有未加static前缀的全局变量和函数都具有全局可见性
//2 存储在静态数据区的变量会在程序开始运行时就完成唯一的一次初始化，只有全局变量和static变量存储在静态存储区，但static可以控制变量的可见范围
//3 static的第三个作用是默认初始化为0，全局变量也具备这一属性
					