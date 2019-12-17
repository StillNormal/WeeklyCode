#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int maze[5][5] = {//�Թ����� 1Ϊǽ ���ϵ�����(0,0)->(4,4)
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

void deep_search() {//dfs ���ɲ��ü�¼��̵ķ�ʽ ��Ϊ��̿����ж�� ���Ҳ�޷��ж϶��������յ��·
	pos predecessor[5][5];//ÿ���㶼���Լ�¼��ǰ��  
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			predecessor[i][j].x = predecessor[i][j].y = 0;
	stack<pos> path;//ֻ��ջ �����Ĳ��ǽ��·��
	pos temp = {0,0};
	maze[0][0] = -1;//����������߹�Ȼ��ѹջ
	path.push(temp);
	while(!path.empty()) {
		temp = path.top();
		path.pop();//��ջ
		if(temp.x==4 && temp.y==4)//�˵����յ�
			break;
		if((temp.x-1)>=0  && maze[temp.x-1][temp.y] == 0) {//�� ������δ�߹�
			maze[temp.x-1][temp.y] = -1;
			predecessor[temp.x-1][temp.y] = temp; //��¼ǰ��
			pos a = {temp.x-1,temp.y};
			path.push(a);
		}
		if((temp.x+1)<=4 && maze[temp.x+1][temp.y] == 0) {//�� 
			maze[temp.x+1][temp.y] = -1;
			predecessor[temp.x+1][temp.y] = temp;
			pos a = {temp.x+1,temp.y};
			path.push(a);
		}
		if((temp.y-1)>=0 && maze[temp.x][temp.y-1] == 0) {//��
			maze[temp.x][temp.y-1] = -1;
			predecessor[temp.x][temp.y-1] = temp;
			pos a = {temp.x,temp.y-1};
			path.push(a);
		}
		if((temp.y+1)<=4 && maze[temp.x][temp.y+1] == 0) {//��
			maze[temp.x][temp.y+1] = -1;
			predecessor[temp.x][temp.y+1] = temp;
			pos a = {temp.x,temp.y+1};
			path.push(a);
		}
	}
	if(temp.x==4 && temp.y==4) {//����ǰ��������յ���������
		cout << temp.x << "," << temp.y << endl;
		while (predecessor[temp.x][temp.y].x!=0 || predecessor[temp.x][temp.y].y!=0) {//����ǰ��ʱ
			int x = predecessor[temp.x][temp.y].x;//temp.x = predecessor[temp.x][temp.y].x ����д������temp.yʱ�ı�temp.x
			temp.y = predecessor[temp.x][temp.y].y;
			temp.x = x;
			cout << temp.x << "," << temp.y << endl;
		}
		cout << "0,0" << endl;//�����������
	}
	else
		cout << "��·�ɴ��յ�" << endl;
}
void breadth_search() {//������������չ����ѵ�ǰ���п��ܶ���չ�������������� �ʺ������Ž�
	pos predecessor[5][5];//ÿ���㶼���Լ�¼��ǰ��  
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			predecessor[i][j].x = predecessor[i][j].y = 0;
	queue<pos> path;//����
	pos temp = {0,0};
	maze[0][0] = -1;//����������߹�Ȼ��ѹջ
	path.push(temp);
	while(!path.empty()) {
		temp = path.front();
		path.pop();//������
		if(temp.x==4 && temp.y==4)//�˵����յ�
			break;
		if((temp.x-1)>=0  && maze[temp.x-1][temp.y] == 0) {//�� ������δ�߹�
			maze[temp.x-1][temp.y] = -1;
			predecessor[temp.x-1][temp.y] = temp; //��¼ǰ��
			pos a = {temp.x-1,temp.y};
			path.push(a);
		}
		if((temp.x+1)<=4 && maze[temp.x+1][temp.y] == 0) {//�� 
			maze[temp.x+1][temp.y] = -1;
			predecessor[temp.x+1][temp.y] = temp;
			pos a = {temp.x+1,temp.y};
			path.push(a);
		}
		if((temp.y-1)>=0 && maze[temp.x][temp.y-1] == 0) {//��
			maze[temp.x][temp.y-1] = -1;
			predecessor[temp.x][temp.y-1] = temp;
			pos a = {temp.x,temp.y-1};
			path.push(a);
		}
		if((temp.y+1)<=4 && maze[temp.x][temp.y+1] == 0) {//��
			maze[temp.x][temp.y+1] = -1;
			predecessor[temp.x][temp.y+1] = temp;
			pos a = {temp.x,temp.y+1};
			path.push(a);
		}
	}
	if(temp.x==4 && temp.y==4) {//����ǰ��������յ��������� 
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
		cout << "��·�ɴ��յ�" << endl;
}
int main() {
	//deep_search();
	//breadth_search();
	system("pause");
}
//���ȣ�bfs��ÿ��һ�����Ͱ����п��ܵ���һ���߷���������,Ȼ������ָ�������һλ��Ҳ����˵bfs�ǰ����п��ܵ��߷�ȫ��ͬʱ��һ�飬
//Ҳ����˵��ͬһʱ�̣��߷��������ﻹδ�жϵ�λ���Ѿ��߹��Ĳ�������ͬ�ģ�����ֻ��1��������һ�������ִ��յ����һ���㷨һ�����ߵĲ������ٵ�
//��dfs�ǰ�һ��·�ߵ����ٻ���һ�������������һ�£�һ�����Ƶ�·�����ߵ��յ㣬dfs���ж�Ϊ��������ˣ���Ȼ�������