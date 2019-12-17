#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)
bool canPlace(int pos, int colum[], int row) {
	for (int i = 0; i < row; i++)
		if (colum[i] == pos || 
			(abs(i - row) == abs(colum[i] - pos)))//已经不同行 这里排除同列和斜的 传入点时row,pos
			return false;
	return true;
}
int main() {
	int colum[8];//记录皇后的列坐标 下标是行号
	for (int i = 0; i < 8; i++)
		colum[i] = -1;//因为是从+1开始算 所有这里初始化不是0
	int count = 0;//记录总的解数
	int row = 0;
	while (row < 8) {
		bool hasPlace = false;
		for (int i = colum[row]+1; i < 8; i++)
			if (canPlace(i, colum, row)) {
				colum[row] = i;
				row++; 
				hasPlace = true;
				break;
			}
		if (!hasPlace) {			
			for (int j = row; j < 8; j++)//清空状态并回溯一行
				colum[j] = -1;
			row--;
		}
		if (row == 8) {//找到一种情况
			count++;
			row--;
		}
		if (row == -1) {//找到最后一种情况后退回row=-1才是循环终止条件
			break;
		}
	}
	cout << count;
	system("pause");
	return 0;
}
