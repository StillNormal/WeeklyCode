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

int cal(Date temp) {//求距元年的天数
	int cnt = 0;
	cnt += temp.day;//该月天数

	switch(temp.month) {
		case 1: cnt += 0; break;//前面月的天数
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
	if(isLeap(temp.year) && temp.month > 2)//闰年二月多一天 当然要超过2月才能多加一天
		cnt++;

	for(int i = 0; i < temp.year; i++)//前面年的天数
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
		if(strcmp(month,"January") == 0)//switch-case后不能跟字符串常量
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

		Date today;//电脑右下得知今天周三
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
			cout << "周" << now << endl;
		}
		else {
			result = result % 7;
			now -= result;
			now = now < 0 ? -now : now;
			cout << "周" << now << endl;
		}
	}	
}