#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
const int M=10;
const int N=10;
const int B=7;//炸弹数
int board[M][N];//10*10棋盘 -1为未开状态 -2为插旗 -3挖到雷炸了 0到8代表周围九宫格内炸弹个数且此时为开状态
struct pos{
	int x;
	int y;
};
pos bomb[B];//记录炸弹坐标


void init() {
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			board[i][j]=-1;
}
void setBomb() {//! 不会生成重复位置 且较均匀 
	srand((int)time(0));
	int num=B;
	for(int i=M*N;i>0;i--) {
		if((rand()%i+1) <= num) {//一个格子分配雷的概率为剩余炸弹数/剩余格子数
			bomb[num-1].x=i/M;//由于内存练习分配 这里若是bonb[num]会在num=B时将值赋给board[0][0]
			bomb[num-1].y=i%M;
			num--;
			if(num==0)
				break;
		}
	}
}
void printBoard() {
	cout << "  ";
	for(int x=0;x<N;x++)//索引横坐标
		cout << x+1 << " ";
	cout << endl;

	for(int i=0;i<M;i++) {
		cout << i+1 << " ";//索引纵坐标
		for(int j=0;j<N;j++)  
			switch(board[i][j]) {
				case 0: cout << "  ";break;
				case 1: cout << "1 ";break;//不要写成'1 '
				case 2: cout << "2 ";break;
				case 3: cout << "3 ";break;
				case 4: cout << "4 ";break;
				case 5: cout << "5 ";break;
				case 6: cout << "6 ";break;
				case 7: cout << "7 ";break;
				case 8: cout << "8 ";break;
				case -1: cout << "? ";break;
				case -2: cout << "P ";break;
				case -3: cout << "X ";break;
			}
		cout << endl;
	}
}
void judgeWin() {
	bool judge=true;
	for(int i=0;i<B;i++) 
		if(board[bomb[B].x][bomb[B].y] != -2)//所有炸弹被设置好旗子
			judge = false;
	if(judge) {
		cout << "win" << endl;
		return ;
	}
}
void dfsOpen(int x,int y) {
	if(x<0 || x>M-1 || y<0 || y>N-1)//! 隔离边界情况
		return;
	if(board[x][y]!=-1)//已开的不需要递归
		return;
	int count=0;
	for(int i=0;i<B;i++)
		if(abs(bomb[i].x-x)<=1 && abs(bomb[i].y-y)<=1)
			count++;
	board[x][y]=count;
	if(count!=0) 
		return;
	else {
		dfsOpen(x-1,y);
		dfsOpen(x+1,y);
		dfsOpen(x,y-1);
		dfsOpen(x,y+1);
		dfsOpen(x-1,y-1);
		dfsOpen(x-1,y+1);
		dfsOpen(x+1,y-1);
		dfsOpen(x+1,y+1);
	}
}

void dig(int x,int y) {
	for(int i=0;i<B;i++) {//炸了
		if(bomb[i].x==x && bomb[i].y==y) {
			board[x][y] = -3;//就不揭示所有炸弹的位置了
			printBoard();
			cout << "game over" << endl;
			system("pause");
			exit(-1);
		}
	}
	dfsOpen(x,y);	//没炸 显示周边区域 
	printBoard();
}
	
void gameLoop() {
	pos tmp;
	int flag_num = B;//可插旗子数与炸弹数一样多
	printBoard();
	while (1) {
		cout << "输入d为挖雷 f为设置/取消旗 q退出 将所有雷标记旗子为胜利 剩余旗子" << flag_num << endl;
		char choose;//不考虑违章输入
		cin >> choose;
		switch(choose) {
			case 'd': cout << "输入挖雷坐标x y" << endl; //比数组下标多1
					cin >> tmp.x >> tmp.y;
					if(tmp.x<1|| tmp.y<1|| tmp.x>M||tmp.y>N) {//小小的异常处理
						cout << "越界 无效" << endl;
						break;
					}
					if(board[tmp.x-1][tmp.y-1] == -1)
						dig(tmp.x-1,tmp.y-1);//内含printBoard
					else if(board[tmp.x-1][tmp.y-1] == -2) {
						flag_num++;//归还一面旗
						board[tmp.x-1][tmp.y-1] = -1;
						dig(tmp.x-1,tmp.y-1);
					}
					else 
						cout << "不是未挖开的或插旗的区域" << endl;
					break;
			case 'f': if(flag_num == 0) {
						  cout << "旗子用完了 尝试挖掉插旗处来获得旗子" << endl;
						  break;
					  }
					cout << "输入旗子坐标x y" << endl;
					cin >> tmp.x >> tmp.y;
					if(tmp.x<1|| tmp.y<1|| tmp.x>M||tmp.y>N) {
						cout << "越界 无效" << endl;
						break;
					}
					if(board[tmp.x-1][tmp.y-1] == -1) {
						board[tmp.x-1][tmp.y-1] = -2;
						flag_num--;
					}
					else if(board[tmp.x-1][tmp.y-1] == -2) {//取消旗
						board[tmp.x-1][tmp.y-1] = -1;
						flag_num++;
					}
					else 
						cout << "不是未挖开的区域" << endl;
					printBoard();
					break;
			case 'q': return;
			default: break;
		}
		judgeWin();
	}
}
void main() {
	init();
	setBomb();
	gameLoop();//游戏循环 不考虑游戏得分
}