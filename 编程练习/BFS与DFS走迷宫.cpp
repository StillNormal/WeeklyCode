#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int maze[5][5] = {//迷宫数组 1为墙 左上到左下(0,0)->(4,4)
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};
struct pos {
	int x;
	int y;
};

void deep_search() {//dfs 不可采用记录后继的方式 因为后继可能有多个 因此也无法判断多条到达终点的路
	pos predecessor[5][5];//每个点都可以记录它前驱  
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			predecessor[i][j].x = predecessor[i][j].y = 0;
	stack<pos> path;//只是栈 存贮的不是解答路径
	pos temp = {0,0};
	maze[0][0] = -1;//将起点标记已走过然后压栈
	path.push(temp);
	while(!path.empty()) {
		temp = path.top();
		path.pop();//出栈
		if(temp.x==4 && temp.y==4)//此点是终点
			break;
		if((temp.x-1)>=0  && maze[temp.x-1][temp.y] == 0) {//上 可走且未走过
			maze[temp.x-1][temp.y] = -1;
			predecessor[temp.x-1][temp.y] = temp; //记录前驱
			pos a = {temp.x-1,temp.y};
			path.push(a);
		}
		if((temp.x+1)<=4 && maze[temp.x+1][temp.y] == 0) {//下 
			maze[temp.x+1][temp.y] = -1;
			predecessor[temp.x+1][temp.y] = temp;
			pos a = {temp.x+1,temp.y};
			path.push(a);
		}
		if((temp.y-1)>=0 && maze[temp.x][temp.y-1] == 0) {//左
			maze[temp.x][temp.y-1] = -1;
			predecessor[temp.x][temp.y-1] = temp;
			pos a = {temp.x,temp.y-1};
			path.push(a);
		}
		if((temp.y+1)<=4 && maze[temp.x][temp.y+1] == 0) {//右
			maze[temp.x][temp.y+1] = -1;
			predecessor[temp.x][temp.y+1] = temp;
			pos a = {temp.x,temp.y+1};
			path.push(a);
		}
	}
	if(temp.x==4 && temp.y==4) {//依据前驱数组从终点向起点输出
		cout << temp.x << "," << temp.y << endl;
		while (predecessor[temp.x][temp.y].x!=0 || predecessor[temp.x][temp.y].y!=0) {//仍有前驱时
			int x = predecessor[temp.x][temp.y].x;//temp.x = predecessor[temp.x][temp.y].x 这样写会在求temp.y时改变temp.x
			temp.y = predecessor[temp.x][temp.y].y;
			temp.x = x;
			cout << temp.x << "," << temp.y << endl;
		}
		cout << "0,0" << endl;//补上起点的输出
	}
	else
		cout << "无路可达终点" << endl;
}
void breadth_search() {//广度优先逐层拓展，会把当前所有可能都拓展出来再向下搜索 适合求最优解
	pos predecessor[5][5];//每个点都可以记录它前驱  
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			predecessor[i][j].x = predecessor[i][j].y = 0;
	queue<pos> path;//队列
	pos temp = {0,0};
	maze[0][0] = -1;//将起点标记已走过然后压栈
	path.push(temp);
	while(!path.empty()) {
		temp = path.front();
		path.pop();//出队列
		if(temp.x==4 && temp.y==4)//此点是终点
			break;
		if((temp.x-1)>=0  && maze[temp.x-1][temp.y] == 0) {//上 可走且未走过
			maze[temp.x-1][temp.y] = -1;
			predecessor[temp.x-1][temp.y] = temp; //记录前驱
			pos a = {temp.x-1,temp.y};
			path.push(a);
		}
		if((temp.x+1)<=4 && maze[temp.x+1][temp.y] == 0) {//下 
			maze[temp.x+1][temp.y] = -1;
			predecessor[temp.x+1][temp.y] = temp;
			pos a = {temp.x+1,temp.y};
			path.push(a);
		}
		if((temp.y-1)>=0 && maze[temp.x][temp.y-1] == 0) {//左
			maze[temp.x][temp.y-1] = -1;
			predecessor[temp.x][temp.y-1] = temp;
			pos a = {temp.x,temp.y-1};
			path.push(a);
		}
		if((temp.y+1)<=4 && maze[temp.x][temp.y+1] == 0) {//右
			maze[temp.x][temp.y+1] = -1;
			predecessor[temp.x][temp.y+1] = temp;
			pos a = {temp.x,temp.y+1};
			path.push(a);
		}
	}
	if(temp.x==4 && temp.y==4) {//依据前驱数组从终点向起点输出 
		cout << temp.x << "," << temp.y << endl;
		while (predecessor[temp.x][temp.y].x!=0 || predecessor[temp.x][temp.y].y!=0) {
			int x = predecessor[temp.x][temp.y].x;
			temp.y = predecessor[temp.x][temp.y].y;
			temp.x = x;
			cout << temp.x << "," << temp.y << endl;
		}
		cout << "0,0" << endl;
	}
	else
		cout << "无路可达终点" << endl;
}
int main() {
	//deep_search();
	//breadth_search();
	system("pause");
}
//首先，bfs是每走一步，就把所有可能的下一步走法存入数组,然后数组指针向后移一位，也就是说bfs是把所有可能的走法全部同时走一遍，
//也就是说在同一时刻，走法的数组里还未判断的位置已经走过的步数是相同的（或者只差1），这样一来，当抵达终点后，那一个算法一定是走的步数最少的
//而dfs是把一条路走到底再换另一条，你可以想象一下，一条很绕的路碰巧走到终点，dfs就判断为计算出来了，当然不是最短