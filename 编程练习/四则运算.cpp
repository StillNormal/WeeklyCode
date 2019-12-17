#include <iostream>
#include <string.h>
using namespace std;

//分治递归做表达式求值，中缀转后缀的方法老是记不住
//输入表达式保证合法，不需考虑除0

bool isNegOp(char* str, int i) {//判断是减号还是负号 
	int pre_pos = i - 1;

	if (!(str[pre_pos] >= '0' && str[pre_pos] <= '9')
		&& str[pre_pos] != ')' && str[pre_pos] != ']' && str[pre_pos] != '}')//非数字0-9且不为右括号
		return true;
	else
		return false;
}

int calculate(char* str, int start, int end) {
	int split_op_pos = start;//分隔操作符位置 对应负号一定在start的位置 不是0
	int left_bracket = 0;//括号的作用是屏蔽里面的操作符

	for (int i = start; i <= end; i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			left_bracket++;

		if (str[i] == '}' || str[i] == ']' || str[i] == ')')
			left_bracket--;

		if (str[i] == '+' && left_bracket == 0)//低优先级运算符优先作为分割符
			split_op_pos = i;

		if (str[i] == '-' && left_bracket == 0 && !isNegOp(str, i))//不能在此处理负号
			split_op_pos = i;

		if (str[i] == '*' && left_bracket == 0 && split_op_pos == start)//选取最右边最低优先级的操作符
			split_op_pos = i;

		if (str[i] == '/' && left_bracket == 0 && split_op_pos == start)
			split_op_pos = i;
	}

	bool isNeg = false;//负数
	switch (str[split_op_pos]) {
	case '+': 
		return calculate(str, start, split_op_pos - 1) + calculate(str, split_op_pos + 1, end);
	case '-': 
		if (isNegOp(str, split_op_pos)) {//负号 不能return -calculate(str, split_op_pos + 1, end)
			isNeg = true;
			break;
		}
		else
			return calculate(str, start, split_op_pos - 1) - calculate(str, split_op_pos + 1, end);
	case '*': 
		return calculate(str, start, split_op_pos - 1) * calculate(str, split_op_pos + 1, end);
	case '/':
		return calculate(str, start, split_op_pos - 1) / calculate(str, split_op_pos + 1, end);
	}

	if (str[start] == '(' || str[start] == '[' || str[start] == '{')//去括号 不能再前面处理
		return calculate(str, start + 1, end - 1);

	if (isNeg)
		start++;
	int number = 0;
	while (str[start] >= '0' && str[start] <= '9') {
		number = number * 10 + str[start] - '0';
		start++;
	}
	if (isNeg)
		number = -number;
	return number;
}

int main() {
	char* str = new char[400];
	while (cin >> str) 
		cout << calculate(str, 0, strlen(str) - 1) << endl;

	return 0;
}