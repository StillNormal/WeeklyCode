#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int n1, n2;
	int A[300], B[300];
	while (cin >> n1) {
		for (int i = 0; i < n1; i++)
			cin >> A[i];
		cin >> n2;
		for (int i = 0; i < n2; i++)
			cin >> B[i];

		sort(A, A + n1);
		sort(B, B + n2);

		int _itr1 = 0;
		int _itr2 = 0;
		while (_itr1 != n1 && _itr2 != n2) {
			if (A[_itr1] < B[_itr2]) {
				cout << A[_itr1];
				_itr1++;
			}
			else if (A[_itr1] > B[_itr2]) {
				cout << B[_itr2];
				_itr2++;
			}
			else {
				cout << A[_itr1];
				_itr1++;
				_itr2++;
			}		
		}
		while (_itr1 != n1) {
			cout << A[_itr1];
			_itr1++;
		}
		while (_itr2 != n2) {
			cout << B[_itr2];
			_itr2++;
		}
		cout << endl;
	}

	return 0;
}