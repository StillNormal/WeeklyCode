#include <iostream>
#include <queue>
#include <string>
using namespace std;

class StringRotation {
public:
	string rotateString(string A, int n, int p) {
		queue<char> chars;
		int i;
		for (i = 0; i <= p; i++)
			chars.push(A[i]);
		for (; i < n; i++)
			A[i - p - 1] = A[i];
		for (i = n - p - 1; i < n; i++) {
			A[i] = chars.front();
			chars.pop();
		}
		return A;
	}
};
int main() {
	StringRotation sr;
	string A = "PQWIVLQQ";
	cout << sr.rotateString(A, A.length(), 5);

	return 0;
}