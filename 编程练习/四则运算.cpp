#include <iostream>
#include <string.h>
using namespace std;

//���εݹ������ʽ��ֵ����׺ת��׺�ķ������Ǽǲ�ס
//������ʽ��֤�Ϸ������迼�ǳ�0

bool isNegOp(char* str, int i) {//�ж��Ǽ��Ż��Ǹ��� 
	int pre_pos = i - 1;

	if (!(str[pre_pos] >= '0' && str[pre_pos] <= '9')
		&& str[pre_pos] != ')' && str[pre_pos] != ']' && str[pre_pos] != '}')//������0-9�Ҳ�Ϊ������
		return true;
	else
		return false;
}

int calculate(char* str, int start, int end) {
	int split_op_pos = start;//�ָ�������λ�� ��Ӧ����һ����start��λ�� ����0
	int left_bracket = 0;//���ŵ���������������Ĳ�����

	for (int i = start; i <= end; i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			left_bracket++;

		if (str[i] == '}' || str[i] == ']' || str[i] == ')')
			left_bracket--;

		if (str[i] == '+' && left_bracket == 0)//�����ȼ������������Ϊ�ָ��
			split_op_pos = i;

		if (str[i] == '-' && left_bracket == 0 && !isNegOp(str, i))//�����ڴ˴�����
			split_op_pos = i;

		if (str[i] == '*' && left_bracket == 0 && split_op_pos == start)//ѡȡ���ұ�������ȼ��Ĳ�����
			split_op_pos = i;

		if (str[i] == '/' && left_bracket == 0 && split_op_pos == start)
			split_op_pos = i;
	}

	bool isNeg = false;//����
	switch (str[split_op_pos]) {
	case '+': 
		return calculate(str, start, split_op_pos - 1) + calculate(str, split_op_pos + 1, end);
	case '-': 
		if (isNegOp(str, split_op_pos)) {//���� ����return -calculate(str, split_op_pos + 1, end)
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

	if (str[start] == '(' || str[start] == '[' || str[start] == '{')//ȥ���� ������ǰ�洦��
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