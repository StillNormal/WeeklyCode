#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)


int main() {
	int* a = new int[1000000];
	int* b = new int[1000000];
	int aI = 0;
	int bI = 0;
	while (scanf("%d", &aI) != EOF) {
		for (int i = 0; i < aI; i++) 
			cin >> a[i];
		cin >> bI;
		for (int i = 0; i < bI; i++) 
			cin >> b[i];
		int midI = (aI + bI) / 2;
		if ((aI + bI) % 2 != 0)
			midI++;
		int cnt1 = 0;
		int cnt2 = 0;
		bool aTurn = true;
		for (int i = 0; i < midI; i++) {
			if (a[cnt1] > b[cnt2]) {
				cnt2++;
				aTurn = false;
			}
			else {//不用考虑=的情况
				cnt1++;
				aTurn = true;
			}
		}
		if (aTurn)
			cout << a[cnt1-1] << endl;
		else
			cout << b[cnt2-1] << endl;	
	}
	return 0;
}
/*
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the non-decreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.     Given two increasing sequences of integers, you are asked to find their median.
输入描述:
Each input file may contain more than one test case.
Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤1000000) is the size of that sequence. Then N integers follow, separated by a space.
It is guaranteed that all the integers are in the range of long int.


输出描述:
For each test case you should output the median of the two given sequences in a line.

输入例子:
4 11 12 13 14
5 9 10 15 16 17

输出例子:
13*/