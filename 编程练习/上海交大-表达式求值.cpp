#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

template <class T>//�����д��
class myStack {
	T ch[100];
	int index;
public:
	myStack() {
		index = 0;
	}
	void push(T x) {//����������ö���T
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
		//myStack<double> num;//������׺ת��׺ �ǶԺ�׺���ʽ��ֵ�õ�
		//myQueue<char> op2;//����Ҫ����׺��ֵ��ɨһ������ѹջ������������ ������һ��ջһ������ ����˳���ǲ���
		int index = 0;
		double suffix[100];
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				double temp = 0;
				while (str[i] >= '0' && str[i] <= '9') {
					//cout << str[i];//������Ǻ�׺���ʽ
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
				while (!op.empty()) {//���ȼ����� ���� ע�����
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
				double b = num.pop();//ע���Ⱥ�˳��
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
����һ�����������ŵı��ʽ���м���
��������:
���ڶ������ݣ�ÿ������һ�У����ʽ�����ڿո�


�������:
������

��������:
6/2+3+3*4

�������:
18*/