#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

bool isLeap(int year) {
	if(((year%4==0) && (year%100!=0)) || (year%400==0))
		return true;
	else
		return false;
}

int cal(Date temp) {//���Ԫ�������
	int cnt = 0;
	cnt += temp.day;//��������

	switch(temp.month) {
		case 1: cnt += 0; break;//ǰ���µ�����
		case 2 : cnt += 31; break;
		case 3 : cnt += 59; break;
		case 4 : cnt += 90; break;
		case 5 : cnt += 120; break;
		case 6 : cnt += 151; break;
		case 7 : cnt += 181; break;
		case 8 : cnt += 212; break;
		case 9 : cnt += 242; break;
		case 10 : cnt += 273; break;
		case 11 : cnt += 303; break;
		case 12 : cnt += 334; break;
	}
	if(isLeap(temp.year) && temp.month > 2)//������¶�һ�� ��ȻҪ����2�²��ܶ��һ��
		cnt++;

	for(int i = 0; i < temp.year; i++)//ǰ���������
		cnt += isLeap(i) ? 366 : 365;

	return cnt;
}

int main() {
	int day;
	char month[20];
	int year;
	while(scanf("%d%s%d",&day,month,&year) != EOF) {
		Date in;
		in.day = day;
		if(strcmp(month,"January") == 0)//switch-case���ܸ��ַ�������
			in.month = 1;
		if(strcmp(month,"Febuary") == 0)
			in.month = 2;
		if(strcmp(month,"March") == 0)
			in.month = 3;
		if(strcmp(month,"April") == 0)
			in.month = 4;
		if(strcmp(month,"May") == 0)
			in.month = 5;
		if(strcmp(month,"June") == 0)
			in.month = 6;
		if(strcmp(month,"July") == 0)
			in.month = 7;
		if(strcmp(month,"Auguest") == 0)
			in.month = 8;
		if(strcmp(month,"September") == 0)
			in.month = 9;
		if(strcmp(month,"October") == 0)
			in.month = 10;
		if(strcmp(month,"November") == 0)
			in.month = 11;
		if(strcmp(month,"December") == 0)
			in.month = 12;
		in.year = year;

		Date today;//�������µ�֪��������
		today.day = 10;
		today.month = 2;
		today.year = 2016;
		int now = 3;
	
		int result = cal(today) - cal(in);
		cout << result << endl;
		if(result < 0) {
			result = -result;
			result = result % 7;
			now += result;
			now = now % 7;
			cout << "��" << now << endl;
		}
		else {
			result = result % 7;
			now -= result;
			now = now < 0 ? -now : now;
			cout << "��" << now << endl;
		}
	}	
}