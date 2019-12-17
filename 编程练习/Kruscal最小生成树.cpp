#include <iostream>
#include <string.h>
using namespace std;

struct Node {//村庄号 村庄号 距离
	int city1;
	int city2;
	int len;
};

void qsort(Node s[], int p, int q) {
	if(p > q) 
		return;
	
	int i, j;
	Node temp;//相同结构会对应赋值
	for(i = p - 1, j = p; j < q; j++) 
		if(s[j].len < s[q].len) {//选最右边的元素为key
			i++;
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	temp = s[i+1];
	s[i+1] = s[q];
	s[q] = temp;

	qsort(s, p, i);
	qsort(s, i+2, q);
}

int main() {
	int num;
	cin >> num;//村庄数
	
	Node* save = new Node[num*(num-1)/2];
	for(int i = 0; i < num*(num-1)/2; i++)
		cin >> save[i].city1 >> save[i].city2 >> save[i].len;

	qsort(save, 0, num*(num-1)/2-1);
	
	int cnt = 0;
	bool* isIn = new bool[num+1];//下标对应 空出第一个不用
	for(int i = 1; i < num+1; i++) 
		isIn[i] = false;//一开始都不在修好的集合中

	for(int i = 0; i < num*(num-1)/2; i++) {
		if(!isIn[save[i].city1] || !isIn[save[i].city2]) {//两村庄中只要有一个不再集合中
			cnt += save[i].len;
			isIn[save[i].city1] = true;
			isIn[save[i].city2] = true;
		}

		bool ok = true;
		for(int i = 1; i < num+1; i++)
			if(!isIn[i]) {
				ok = false;
				break;
			}
		if(ok)//所有都在集合中 城市连好了
			break;
	}

	cout << "最短路长为 " << cnt << endl;
	system("pause");
}