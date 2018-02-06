/*

2018 Feb 06, made by Moon

*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int c[1001] = { 0, };
	int dp[1001] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		c[i] = p;
	}

	dp[1] = c[1];
	for (int i = 2; i <= n; i++) {
		if (!dp[i]) {
			int maxV = 0;
			for (int j = 0; j < i; j++) {
				maxV = max(maxV, dp[j] + c[i-j]);
			}
			dp[i] = maxV;
		}
	}

	cout << dp[n] << endl;

	return 0;
}
