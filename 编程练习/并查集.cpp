#include <iostream>
#include <string.h>
using namespace std;

int findRoot(int father[], int n) {
	int root = n;
	while(father[root] != -1) {
		root = father[root];
	}

	int temp;
	while(father[n] != -1) {//再遍历到根节点 做路径压缩
		temp = father[n];
		father[n] = root;
		n = temp;
	}

	return root;
}

int main() {
	int city, road;
	cin >> city >> road;//城市数 道路数

	int* father = new int[city+1];//下标对应 空出第一个不用
	for(int i = 1; i < city+1; i++)
		father[i] = -1;//值为-1代表单独成根节点

	int m, n;
	for(int i = 0; i < road; i++) {
		cin >> m >> n;
		father[m] = findRoot(father, n);//默认找后一个城市的根节点 让前一个城市指向它
	}
	
	int cnt = 0;
	for(int i = 1; i < city+1; i++)
		if(father[i] == -1)
			cnt++;
	cout << "还需修路的条数 " << cnt-1 << endl;
	system("pause");
}