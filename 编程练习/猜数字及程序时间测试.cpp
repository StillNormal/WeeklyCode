#include <iostream>
#include <time.h>
using namespace std;

void game() {
	srand((int)time(NULL));
	int level;
	printf("Level: \n1 easy 1-100\n2 normal 1-200\n3 hard 1-300\n");//��cout��endl << ����Щ
	do {
		cout << "You must choose a num from 1-3" << endl;
		cin >> level;
	}while(level !=1 && level !=2 && level!=3);

	int M = level*100;
	int number = rand() % M + 1;  //����1-M�������
	
	int n=0;
	int i=0;
	clock_t t1,t2;//��ʱ�жϷ�Ӧ�ٶ� clock_t�ǳ�����
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
	t2=clock();//cpuʱ�� ����
	cout << "Correct,use " << i << " guess and " << (t2-t1)/1000 << " s" << endl;
}

int main() {
	game();
	system("pause");
}
//time���ش�1970��1��1��0ʱ�����ڵ���������ϵͳʱ�䡣
//clock���Խ���������˽���ʹ��cpu���ܺ���������������������ִ�е��ٶȡ�
