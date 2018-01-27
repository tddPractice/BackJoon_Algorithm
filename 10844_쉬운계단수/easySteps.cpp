#include <iostream>
using namespace std;
int dp[101][10];
int n;

int find(int i, int j) {
	
	if (i == 1 && j == 0) return 0;
	if (i == 1 && j > 0 && j<10) return 1;
	if (i == 0 || i < 0 || j<0 || j>9) return 0;
	if (dp[i][j] == 0) 
		dp[i][j] = (find(i - 1, j - 1) + find(i - 1, j + 1)) % 1000000000;
	
	return dp[i][j];
}

int main() {
	cin >> n;
	int res = 0;
	for (int i = 0; i < 10; i++){
        res += find(n, i);
        res %= 1000000000;
    }

	cout << res;

	return 0;
}
