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
class snake
{
	COORD body[M];
	COORD food;//һ��ֻ����һ��ʳ��
	bool food_flag;
	int length;
	bool dead;
	char direction;
	int score;
	public:
		snake();
		void drawsnake();
		void Pause();
		void game();
		void move(char x);
		void gameOver();
		bool judge_hit();//ײ���Լ�
		int random(int x, int y);
		void makeFood();
		bool judge_eat();//�Ե�ʳ��
		void grow();
};

snake::snake() 
{
	dead=0;
	direction='w';
	body[0].X=body[0].Y=10;
	length=1;
	score=0;
	food.X=food.Y=15;
	food_flag=1;
}
void snake::drawsnake()
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	for(int i=0;i<length;i++) {
		SetPos(body[i].X,body[i].Y);
		cout << "*";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}


int snake::random(int x, int y)//(x,y)�������
{
	int k=x+rand()%(y-x+1);
	return k;
}

void snake::Pause()
{
	SetPos(65,2);
	cout<<"Pause...";
	char x=_getch();
	while(x!='p')
		x=_getch();
	SetPos(65,2);
	cout<<"        ";
	
}
void snake::gameOver()
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
	exit(0);//������Ϸ
}



void snake::move(char x)
{
	for(int i=length-1;i>0;i--)//���Ǩ�� �Ӻ���ǰ���� ̰���ߺ���
		body[i]=body[i-1];

	if(x == 'a')//��ͷ
		body[0].X--;		
	if(x == 's')
		body[0].Y++;	
	if(x == 'd')
		body[0].X++;
	if(x == 'w')
		body[0].Y--;

	if(body[0].X == 0)//��Խǽ
		body[0].X=49;
	if(body[0].X == 50)
		body[0].X=1;
	if(body[0].Y == 0)
		body[0].Y=23;
	if(body[0].Y == 24)
		body[0].Y=1;
}
bool snake::judge_hit()
{
	for(int i=1;i<length;i++)
		if(body[0].X==body[i].X && body[0].Y==body[i].Y)
			return 1;
	return 0;
}
bool snake::judge_eat()
{
	for(int i=0;i<length;i++)
		if(food.X==body[i].X && food.Y==body[i].Y)
			return 1;
	return 0;
}
void snake::makeFood() {//��ʾʳ�ﲢ��ûʳ��ʱˢ��һ��ʳ��
	if(!food_flag) {
		SetPos(food.X,food.Y);
		cout << " ";//��ȥ���Ե���ʳ��
		bool repeat=true;
		while(repeat) {
			repeat=false;
			food.X=random(1,49);
			food.Y=random(1,23);
			for(int i=0;i<length;i++) {
				if(body[i].X==food.X && body[i].Y==food.Y) //ʳ������ʱ���������غ�
					repeat=true;
			}
		}
		food_flag=true;
	}
	SetPos(food.X,food.Y);
	cout << "��";
}
void snake::grow() {
	length++;
	if(length==M)
		gameOver();//�ﵽ���ĳ�������һ��ʤ��

	move(direction);
}
void snake::game() 
{	
	while(1)//ͨ��������e��return
	{	
		Sleep(100);
		if(_kbhit())
		{
			char x = _getch();
			if (('a' == x && direction=='d') || ('d' == x && direction=='a') || ('w' == x && direction=='s') || ('s' == x && direction=='w'))
				;//��Ϊ������Ч
			else if ('a' == x || 's' == x || 'd' == x || 'w' == x)
				direction=x;					
			else if ('p' == x)
				Pause();
			else if( 'e' == x)
				gameOver();//��ʱdead=0
		}
		SetPos(body[length-1]);//length���±��1
		cout << " ";//��βλ�����
		move(direction);
		if(judge_hit()) {
			Sleep(1000);
			dead=true;
			gameOver();
		}
		if(judge_eat()) {
			food_flag=false;//ʳ��û��
			score+=1;
			grow();//�߳���һ��
		}
		makeFood();//ע��ʳ��ˢ�µ�ʱ��
		drawsnake();		
	}
}


void  Start()
{
	SetPos(30, 8);
	cout<<"   ̰������Ϸ "<<endl;
	drawRow(6, 0, 79, '-');
	drawRow(10, 0, 79, '-');
	while(1){
		SetPos(28,14);
		cout<<"                       ";
		Sleep(1000);//sleep 1s.
		SetPos(28,14);
		cout<<"Press any key to start!";
		Sleep(1000);//sleep 1s.
		if( _kbhit() )  {
			system("cls");
			return ;	
		}
	}
}

void drawMap()
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
	cout<<"��ʾ:";
	SetPos(52,14);
	cout<<"a,s,d,w �������ƶ�";
	SetPos(52,16);
	cout<<"p ��ͣ��Ϸ e �˳���Ϸ";
}
void main()
{
	HideCursor();	//���ع��
	srand((int)time(NULL));
	//Start();//Ϊ�˿�ݺ��Կ�ʼ����
	drawMap();
	snake a;
	a.game();
}
