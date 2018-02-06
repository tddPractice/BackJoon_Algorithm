/*

2018 Feb 06, made by Moon

*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	int color[1001][1001] = { 0, };
	int dp[1001][1001] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		
		color[i][0] = r;
		color[i][1] = g;
		color[i][2] = b;
	}

	dp[1][0] = color[1][0];
	dp[1][1] = color[1][1];
	dp[1][2] = color[1][2];
	for (int i = 2; i <= n; i++) {
		if (!dp[i][0]) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
		}
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;

	return 0;
}
