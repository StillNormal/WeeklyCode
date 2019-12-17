#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
const int M=10;
const int N=10;
const int B=7;//ը����
int board[M][N];//10*10���� -1Ϊδ��״̬ -2Ϊ���� -3�ڵ���ը�� 0��8������Χ�Ź�����ը�������Ҵ�ʱΪ��״̬
struct pos{
	int x;
	int y;
};
pos bomb[B];//��¼ը������


void init() {
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			board[i][j]=-1;
}
void setBomb() {//! ���������ظ�λ�� �ҽϾ��� 
	srand((int)time(0));
	int num=B;
	for(int i=M*N;i>0;i--) {
		if((rand()%i+1) <= num) {//һ�����ӷ����׵ĸ���Ϊʣ��ը����/ʣ�������
			bomb[num-1].x=i/M;//�����ڴ���ϰ���� ��������bonb[num]����num=Bʱ��ֵ����board[0][0]
			bomb[num-1].y=i%M;
			num--;
			if(num==0)
				break;
		}
	}
}
void printBoard() {
	cout << "  ";
	for(int x=0;x<N;x++)//����������
		cout << x+1 << " ";
	cout << endl;

	for(int i=0;i<M;i++) {
		cout << i+1 << " ";//����������
		for(int j=0;j<N;j++)  
			switch(board[i][j]) {
				case 0: cout << "  ";break;
				case 1: cout << "1 ";break;//��Ҫд��'1 '
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
		if(board[bomb[B].x][bomb[B].y] != -2)//����ը�������ú�����
			judge = false;
	if(judge) {
		cout << "win" << endl;
		return ;
	}
}
void dfsOpen(int x,int y) {
	if(x<0 || x>M-1 || y<0 || y>N-1)//! ����߽����
		return;
	if(board[x][y]!=-1)//�ѿ��Ĳ���Ҫ�ݹ�
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
	for(int i=0;i<B;i++) {//ը��
		if(bomb[i].x==x && bomb[i].y==y) {
			board[x][y] = -3;//�Ͳ���ʾ����ը����λ����
			printBoard();
			cout << "game over" << endl;
			system("pause");
			exit(-1);
		}
	}
	dfsOpen(x,y);	//ûը ��ʾ�ܱ����� 
	printBoard();
}
	
void gameLoop() {
	pos tmp;
	int flag_num = B;//�ɲ���������ը����һ����
	printBoard();
	while (1) {
		cout << "����dΪ���� fΪ����/ȡ���� q�˳� �������ױ������Ϊʤ�� ʣ������" << flag_num << endl;
		char choose;//������Υ������
		cin >> choose;
		switch(choose) {
			case 'd': cout << "������������x y" << endl; //�������±��1
					cin >> tmp.x >> tmp.y;
					if(tmp.x<1|| tmp.y<1|| tmp.x>M||tmp.y>N) {//СС���쳣����
						cout << "Խ�� ��Ч" << endl;
						break;
					}
					if(board[tmp.x-1][tmp.y-1] == -1)
						dig(tmp.x-1,tmp.y-1);//�ں�printBoard
					else if(board[tmp.x-1][tmp.y-1] == -2) {
						flag_num++;//�黹һ����
						board[tmp.x-1][tmp.y-1] = -1;
						dig(tmp.x-1,tmp.y-1);
					}
					else 
						cout << "����δ�ڿ��Ļ���������" << endl;
					break;
			case 'f': if(flag_num == 0) {
						  cout << "���������� �����ڵ����촦���������" << endl;
						  break;
					  }
					cout << "������������x y" << endl;
					cin >> tmp.x >> tmp.y;
					if(tmp.x<1|| tmp.y<1|| tmp.x>M||tmp.y>N) {
						cout << "Խ�� ��Ч" << endl;
						break;
					}
					if(board[tmp.x-1][tmp.y-1] == -1) {
						board[tmp.x-1][tmp.y-1] = -2;
						flag_num--;
					}
					else if(board[tmp.x-1][tmp.y-1] == -2) {//ȡ����
						board[tmp.x-1][tmp.y-1] = -1;
						flag_num++;
					}
					else 
						cout << "����δ�ڿ�������" << endl;
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
	gameLoop();//��Ϸѭ�� ��������Ϸ�÷�
}