#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

//�ݹ鸴�Ӷȴ󣬿ɳ��Ըĳ�ջ���Ϳռ临�Ӷȣ���̬�滮����ʱ�临�Ӷȣ�

int n;
int m[10];
int x[10];
map<int, int> saveWeight;

void addWeight(int total, int nowI, int endI) {
	if (nowI == endI) {
		saveWeight.insert(std::pair<int, int>(total, 0));//0ֵû���� ֻ������map���ظ�Ԫ��insert���޷����� ע��pair���÷�
		return;
	}
	for (int i = 0; i <= x[nowI]; i++) {
		addWeight(total + m[nowI] * i, nowI + 1, endI);//������nowI++
	}
}

int main() {
	while (cin >> n) {//��ʵ��һ��Ҳ���ж�һ�������Ƿ����
		for (int i = 0; i < n; i++) {
			cin >> m[i];
			//cin >> x[i];//����һ���
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

