#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

//递归复杂度大，可尝试改成栈降低空间复杂度，或动态规划降低时间复杂度，

int n;
int m[10];
int x[10];
map<int, int> saveWeight;

void addWeight(int total, int nowI, int endI) {
	if (nowI == endI) {
		saveWeight.insert(std::pair<int, int>(total, 0));//0值没有用 只是利用map的重复元素insert会无法插入 注意pair的用法
		return;
	}
	for (int i = 0; i <= x[nowI]; i++) {
		addWeight(total + m[nowI] * i, nowI + 1, endI);//不能用nowI++
	}
}

int main() {
	while (cin >> n) {//其实读一行也能判断一组数据是否结束
		for (int i = 0; i < n; i++) {
			cin >> m[i];
			//cin >> x[i];//不能一起读
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}		
		addWeight(0, 0, n);
		//map<int, int>::iterator iter;
		//for (iter = saveWeight.begin(); iter != saveWeight.end(); iter++)
			//cout << iter->first << " ";
		cout << saveWeight.size() << endl;
		saveWeight.clear();
	}
	return 0;
}

