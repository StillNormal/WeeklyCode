#include <iostream>
using namespace std;
const int M=10;//������10��
int recurse(int x,int y) {//�ݹ� ������
	if(y==1 || x==y)
		return 1;
	else
		return recurse(x-1,y-1)+recurse(x-1,y);
}
void print() {
	for(int i=1;i<=M;i++) {
		for(int j=1;j<=i;j++)//��i��i����
			cout << recurse(i,j) << " ";
		cout << endl;
	}
}
int main() {//���ά������ 
	print();
	system("pause");
}

					