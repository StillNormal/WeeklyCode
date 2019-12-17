#include <iostream>
using namespace std;
const int M=10;//三角形10行
int recurse(int x,int y) {//递归 不保存
	if(y==1 || x==y)
		return 1;
	else
		return recurse(x-1,y-1)+recurse(x-1,y);
}
void print() {
	for(int i=1;i<=M;i++) {
		for(int j=1;j<=i;j++)//第i行i个数
			cout << recurse(i,j) << " ";
		cout << endl;
	}
}
int main() {//或二维矩阵做 
	print();
	system("pause");
}

					