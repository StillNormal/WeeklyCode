#include <iostream>
#include <string.h>
using namespace std;

//单源点到所有结点的距离 
int main() {
	int num;
	cin >> num;//路口数
	int road;
	cin >> road;//路数
	
	int a[20][20];
	bool isIn[20];//已加入的结点集合
	int dist[20];//一点到其他所有点的最短距离

	for(int i = 1; i < num+1; i++)
		for(int j = 1; j < num+1; j++) 
			a[i][j] = 999;//后面比较 理论上要无穷大 而不能是-1这种小的 代表不可达
	isIn[1] = true;//此处默认求第一个到最后一个的距离 于是集合中先加入第一个结点
	for(int i = 1; i < num+1; i++) {
		isIn[i] = false;
		dist[i] = a[1][i];//以第一个结点为标准 启动
	}
	dist[1] = 0;//第一个结点到自身的距离为0

	int x, y;
	for(int i = 0; i < road; i++) {
		cin >> x >> y;
		cin >> a[x][y];
		a[y][x] = a[x][y];//注意无向图
	}

	int left = num;
	while(left > 0) {//还有点没加入集合
		int min = 999;
		int temp;
		for(int j = 1; j < num+1; j++)//对未进入集合的点找最近的加入集合
			if(min > dist[j] && !isIn[j]) {				
				temp = j;
				min = dist[j];
			}
		isIn[temp] = true;
		
		dist[temp] = min;//只需通过新加入的点来更新未进入集合的点的距离
		for(int j = 1; j < num+1; j++)
			if(dist[j] > dist[temp] + a[temp][j] && !isIn[j]) 
				dist[j] = dist[temp] + a[temp][j];
		left--;
	}

	cout << "从第一个结点到所有结点的最短路长为 ";
	for(int i = 1; i < num+1; i++)
		cout << dist[i] << " ";
	system("pause");
}