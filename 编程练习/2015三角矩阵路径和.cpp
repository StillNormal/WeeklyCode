#include<iostream>	
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100][100];	
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)//注意这个=号
			cin >> a[i][j];

	int result[100][100];	
	result[0][0] = a[0][0];
	for(int i = 1; i < n; i++)//从1,0开始 即第二行第一个
		for(int j = 0; j <= i; j++) {
			if(j == 0)//每行最左
				result[i][j] = result[i-1][j] + a[i][j];
			else if(j == i)//每行最右
				result[i][j] = result[i-1][j-1] + a[i][j];
			else {
				result[i][j] = result[i-1][j-1] < result[i-1][j] ? result[i-1][j-1] : result[i-1][j];
				result[i][j] += a[i][j];
			}
		}
	
	int min = result[n-1][0];
	for(int i = 1; i < n; i++) 
		if(min > result[n-1][i])
			min = result[n-1][i];
	cout << min;
	system("pause");
	return 0;
}

/*
Description
Given an N layers triangle in mathematic like the graph below. There are many ways that you could walk from the top to the bottom of the triangle. Every step, you can walk from one point to its left below or right below. Your hurt is the total number added though the way you choose. Now, your mission is to calculate the minimum hurt you could get.

     2

     6 2

     1 8 4

     1 5 6 8

For example, at point 4, you could only walk to 6 (left below) or 8 (right below).


Input
The first line is a positive integer n, representing the height of triangle’s edge. (n < 1000)

The second line to n + 1 line, is the data of the triangle described above.

Output
The minimum number of the hurt you could get. 


Sample Input
4
2
6 2
1 8 4
1 5 6 8
Sample Output
10

*/