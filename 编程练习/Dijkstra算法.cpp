#include <iostream>
#include <string.h>
using namespace std;

//��Դ�㵽���н��ľ��� 
int main() {
	int num;
	cin >> num;//·����
	int road;
	cin >> road;//·��
	
	int a[20][20];
	bool isIn[20];//�Ѽ���Ľ�㼯��
	int dist[20];//һ�㵽�������е����̾���

	for(int i = 1; i < num+1; i++)
		for(int j = 1; j < num+1; j++) 
			a[i][j] = 999;//����Ƚ� ������Ҫ����� ��������-1����С�� �����ɴ�
	isIn[1] = true;//�˴�Ĭ�����һ�������һ���ľ��� ���Ǽ������ȼ����һ�����
	for(int i = 1; i < num+1; i++) {
		isIn[i] = false;
		dist[i] = a[1][i];//�Ե�һ�����Ϊ��׼ ����
	}
	dist[1] = 0;//��һ����㵽����ľ���Ϊ0

	int x, y;
	for(int i = 0; i < road; i++) {
		cin >> x >> y;
		cin >> a[x][y];
		a[y][x] = a[x][y];//ע������ͼ
	}

	int left = num;
	while(left > 0) {//���е�û���뼯��
		int min = 999;
		int temp;
		for(int j = 1; j < num+1; j++)//��δ���뼯�ϵĵ�������ļ��뼯��
			if(min > dist[j] && !isIn[j]) {				
				temp = j;
				min = dist[j];
			}
		isIn[temp] = true;
		
		dist[temp] = min;//ֻ��ͨ���¼���ĵ�������δ���뼯�ϵĵ�ľ���
		for(int j = 1; j < num+1; j++)
			if(dist[j] > dist[temp] + a[temp][j] && !isIn[j]) 
				dist[j] = dist[temp] + a[temp][j];
		left--;
	}

	cout << "�ӵ�һ����㵽���н������·��Ϊ ";
	for(int i = 1; i < num+1; i++)
		cout << dist[i] << " ";
	system("pause");
}