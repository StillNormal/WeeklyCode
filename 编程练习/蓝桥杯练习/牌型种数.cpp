#include <iostream>
using namespace std;


int ans = 0;
void dfs(int cardNum, int cardId) {
	if (cardNum == 13) {
		ans++;
		return;
	}

	if (cardId == 13) 
		return;
	
	for (int i = 0; i <= 4; i++)
		dfs(cardNum + i, cardId + 1);
}

int main() {
	dfs(0, 0);
	cout << ans;
	system("pause");
	return 0;
}