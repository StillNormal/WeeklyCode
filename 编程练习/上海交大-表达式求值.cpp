#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

template <class T>//这里的写法
class myStack {
	T ch[100];
	int index;
public:
	myStack() {
		index = 0;
	}
	void push(T x) {//所有类型最好都是T
		ch[index] = x;
		index++;
	}
	T pop() {
		index--;
		return ch[index];
	}
	T top() {
		return ch[index - 1];
	}
	bool empty() {
		return index == 0 ? true : false;
	}
	int getNum() {
		return index;
	}
};
template <class T>
class myQueue {
	T ch[100];
	int front;
	int rear;
public:
	myQueue() {
		front = 0;
		rear = 0;
	}
	void push(T x) {
		ch[rear] = x;
		rear++;
	}
	T pop() {
		if (front < rear) {
			T temp = ch[front];
			front++;
			return temp;
		}
	}
	T top() {
		return ch[front];
	}
	bool empty() {
		return front >= rear ? true : false;
	}
	int getNum() {
		return rear - front;
	}
};
int main() {
	char str[100];
	while (scanf("%s", str) != EOF) {
		myStack<char> op;
		//myStack<double> num;//不是中缀转后缀 是对后缀表达式求值用的
		//myQueue<char> op2;//这里要理解后缀求值是扫一遍数字压栈，操作符处理 但不是一个栈一个队列 这样顺序还是不对
		int index = 0;
		double suffix[100];
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				double temp = 0;
				while (str[i] >= '0' && str[i] <= '9') {
					//cout << str[i];//输出就是后缀表达式
					temp *= 10;
					temp += str[i] - '0';
					i++;
				}
				suffix[index] = temp;
				index++;
			}
			if (str[i] == '*' || str[i] == '/') {
				while (op.top() == '*'|| op.top() == '/') {
					suffix[index] = op.top();
					index++;
					op.pop();
					//cout << op.pop();
				}
				op.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-') {
				while (!op.empty()) {//优先级大于 等于 注意等于
					suffix[index] = op.top();
					index++;
					op.pop();
					//cout << op.pop();
				}
				op.push(str[i]);
			}
		}
		while (!op.empty()) {
			suffix[index] = op.top();
			index++;
			op.pop();
			//cout << op.pop();
		}
		//cout << endl;

		myStack<double> num;
		for (int i = 0; i < index; i++) {
			if (suffix[i] != '*' && suffix[i] != '/' && suffix[i] != '+' && suffix[i] != '-')
				num.push(suffix[i]);
			else {
				double b = num.pop();//注意先后顺序
				double a = num.pop();
				double c;
				if (suffix[i] == '+')
					c = a + b;
				else if (suffix[i] == '-')
					c = a - b;
				else if (suffix[i] == '*')
					c = a * b;
				else
					c = a / b;
				num.push(c);
			}
		}
		cout << num.pop() << endl;
	}
	return 0;
}
/*
对于一个不存在括号的表达式进行计算
输入描述:
存在多种数据，每组数据一行，表达式不存在空格


输出描述:
输出结果

输入例子:
6/2+3+3*4

输出例子:
18*/