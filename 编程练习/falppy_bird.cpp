#include <iostream>
using namespace std;
#include<windows.h>
#include <conio.h>
#include<time.h>
const int M=100;
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void SetPos(COORD a) 
{
	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j)
{
	COORD pos={i, j};
	SetPos(pos);

}
void drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1,y);
	for(int i = 0; i <= (x2-x1); i++)
		cout<<ch;
}
void drawCol(int x, int y1, int y2, char ch)
{
	int y=y1;
	while(y!=y2+1)
	{
		SetPos(x, y);
		cout<<ch;
		y++;
	}
}
class bird
{
	COORD position;
	COORD barrier[3];//一开始限定3个障碍 用坐标标记障碍的最高点 与顶或底连线即为一道墙 其中偶数下标的0、2号与底做垂线
	bool dead;
	int score;
	int t;//下落速度1/2gt^2
	public:
		bird();
		void drawbird();
		void Pause();
		void game();
		void move(char x);
		void gameOver();
		bool judge_hit();//撞到障碍
		int random(int x, int y);
		void fall();
		void barrier_move();
		void create_barrier(int num);
};

bird::bird() 
{
	dead=false;
	position.X = 1;
	position.Y = 5;
	barrier[0].X = 9;//三个X间距就此定下来
	barrier[0].Y  = 17;
	barrier[1].X = 23;
	barrier[1].Y  = 6;
	barrier[2].X = 38;
	barrier[2].Y = 14;
	score=0;
	t=0;
}
void bird::drawbird()
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	SetPos(position);
	cout << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

int bird::random(int x, int y)//(x,y)间随机数
{
	int k=x+rand()%(y-x+1);
	return k;
}

void bird::Pause()
{
	SetPos(65,2);
	cout<<"Pause...";
	char x=_getch();
	while(x!='p')
		x=_getch();
	SetPos(65,2);
	cout<<"        ";
	
}
void bird::gameOver()
{
	system("cls");				
	drawRow(  9, 28, 53, '*');
	drawCol( 28, 9, 15, '*');
	drawRow( 15, 28, 53, '*');
	drawCol( 53, 9, 15, '*');
	
	SetPos(36,12);
	string str;
	if(dead)
		str="You Lose!";
	else
		str="End of Game!";
	for(int i=0; i<str.size(); i++)
	{
		Sleep(80);
		cout<<str[i];
	}
	Sleep(1000);
	SetPos(34,13);
	cout << "Score:    " << score ;
	Sleep(3000);
	exit(0);//结束游戏
}

void bird::move(char x)
{
	SetPos(position);//清空上个位置小鸟
	cout << " ";
	
	if(x == 'w')
		position.Y--;

	if(position.Y == 23)
		position.Y=23;
	if(position.Y == 1)
		position.Y=1;

	drawbird();	
}
void bird::fall() {
	SetPos(position);//清空上个位置小鸟
	cout << " ";

	position.Y += t;
	t += 1;
	if(position.Y >= 23)
		position.Y=23;

	drawbird();
}
void bird::barrier_move() {//实则只移动一个顶点 但画的是一条垂线
	drawCol(barrier[0].X,barrier[0].Y,23,' ');//先清掉上一次的
	drawCol(barrier[1].X,1,barrier[1].Y,' ');
	drawCol(barrier[2].X,barrier[2].Y,23,' ');	
	barrier[0].X--;
	barrier[1].X--;
	barrier[2].X--;
	for(int i=0;i<3;i++)
		if(barrier[i].X == 0) 
			create_barrier(i);
	drawCol(barrier[0].X,barrier[0].Y,23,'|');//地图的底与顶纵坐标是1和23
	drawCol(barrier[1].X,1,barrier[1].Y,'|');
	drawCol(barrier[2].X,barrier[2].Y,23,'|');
}
void bird::create_barrier(int num) {
	barrier[num].X = 47;
	barrier[num].Y = random(7,16);
	score++;//过了一根障碍得一分
}
	
bool bird::judge_hit()
{
	if(position.X == barrier[0].X)
		if(position.Y >= barrier[0].Y)
			return 1;
	if(position.X == barrier[1].X)
		if(position.Y <= barrier[1].Y)
			return 1;
	if(position.X == barrier[2].X)
		if(position.Y >= barrier[2].Y)
			return 1;
	return 0;
}

void bird::game() //游戏难度不会随分数增加而加大
{	
	int clk_flag=0;//障碍移动、下落时钟和总时钟应该包含关系 不应该太快
	while(1)//通过死亡或e键return
	{	
		Sleep(100);//总时钟
		if(_kbhit())
		{
			char x = _getch();
			if ('w' == x) {//向上移动可以抵消下落初始速度
				t=0;
				move(x);
			}
			else if ('p' == x)
				Pause();
			else if( 'e' == x)
				gameOver();//此时dead=0
		}
		if(judge_hit()) {
			drawbird();//死时停一下
			Sleep(1000);
			dead=true;
			gameOver();
		}
		if(clk_flag == 3) {
			fall();//重力下落
			barrier_move();//障碍物左移 同时画 并考虑是否到最左端 以及创造新障碍物
			clk_flag=0;
		}
		clk_flag++;	
	}
}


void drawMap()//宽（1,49） 高（1,23）
{
	
	drawRow( 0, 0, 50, '=');//drawRow(int y, int x1, int x2, char ch);
	drawCol( 0, 1, 24, '|');//drawCol(int x, int y1, int y2, char ch);
	drawRow( 24, 0, 50, '=');
	drawCol( 50, 1, 24, '|');
	
	drawRow( 0, 51, 78, '*');
	drawRow( 4, 51, 78, '*');
	drawRow( 8, 51, 78, '*');
	drawRow( 24, 51,78, '*');
	drawCol( 78, 0, 24, '|'); 

	SetPos(52,12);
	cout<<"提示:";
	SetPos(52,14);
	cout<<"w 控制小鸟上飞";
	SetPos(52,16);
	cout<<"p 暂停游戏 e 退出游戏";
}
void main()
{
	HideCursor();	//隐藏光标
	srand((int)time(NULL));
	drawMap();
	bird a;
	a.game();
}
