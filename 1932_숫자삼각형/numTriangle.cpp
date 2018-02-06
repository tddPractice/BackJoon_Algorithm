/*

2018 Feb 06, made by Moon

*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[502][502] = { 0, };
	int sum[502][502] = { 0, };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int size;
			cin >> size;
			dp[i][j] = size;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			sum[i][j] = max(sum[i-1][j], sum[i-1][j-1]) + dp[i][j];
		}
	}

	int maxV = sum[n][1];
	for (int i = 2; i <= n; i++) {
		maxV = max(sum[n][i], maxV);
	}
	cout << maxV << endl;

	return 0;
}
