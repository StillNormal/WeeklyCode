#include <iostream>
#include <string>
using namespace std;

bool flag = false;//�Ƿ��ܵõ�24��

void cal(double list[], int index, double val) {
	if (index == 4) {
		if (val == 24) {
			flag = true;
		}
		return;
	}

	cal(list, index + 1, val + list[index]);
	cal(list, index + 1, val - list[index]);
	cal(list, index + 1, val * list[index]);
	if (list[index] != 0) 		
		cal(list, index + 1, val / list[index]);//����double�ͻ��
	return;
}

void fillList(double list[], double num[], int index) {
	if (index == 4) {//�ݹ����
		//cout << list[0] << list[1] << list[2] << list[3] << endl;
		cal(list, 1, list[0]);
		return;
	}

	double temp_num[4];//��Ҫ�������в�����Ӱ��
	for (int i = 0; i < 4; i++)
		temp_num[i] = num[i];

	for (int i = index; i < 4; i++) {
		double temp;
		temp = temp_num[index];
		temp_num[index] = temp_num[i];
		temp_num[i] = temp;
		list[index] = temp_num[index];
		fillList(list, temp_num, index+1);
	}
}

int main() {
	double num[4];
	while (cin >> num[0] >> num[1] >> num[2] >> num[3]) {
		double list[4];//24���������
		fillList(list, num, 0);
		if (flag)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		flag = false;
	}
	return 0;
}