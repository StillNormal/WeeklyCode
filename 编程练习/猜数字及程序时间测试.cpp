#include <iostream>
#include <time.h>
using namespace std;

void game() {
	srand((int)time(NULL));
	int level;
	printf("Level: \n1 easy 1-100\n2 normal 1-200\n3 hard 1-300\n");//比cout的endl << 方便些
	do {
		cout << "You must choose a num from 1-3" << endl;
		cin >> level;
	}while(level !=1 && level !=2 && level!=3);

	int M = level*100;
	int number = rand() % M + 1;  //产生1-M的随机数
	
	int n=0;
	int i=0;
	clock_t t1,t2;//计时判断反应速度 clock_t是长整型
	while(true) {
		t1=clock();
		cout << "Guess:  ";
		cin >> n;
		i++;
		if(n>number)
			cout << "Big" << endl;
		else if(n<number)
			cout << "Small" << endl;
		else
			break;
	}
	t2=clock();//cpu时间 毫秒
	cout << "Correct,use " << i << " guess and " << (t2-t1)/1000 << " s" << endl;
}

int main() {
	game();
	system("pause");
}
//time返回从1970年1月1日0时到现在的秒数，即系统时间。
//clock是自进程启动后此进程使用cpu的总毫秒数，常用来测试任务执行的速度。
