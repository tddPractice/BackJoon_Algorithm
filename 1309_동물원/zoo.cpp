/*

2018 Mar 16, made by Moon

*/
#include <cstdio>

int main() {
	int n, dp[100001][3] = { 0 };
	int mod = 9901;
	scanf("%d", &n);

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		if (!dp[i][0]) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
			dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		}
	}

	printf("%d\n", (dp[n][0] + dp[n][1] + dp[n][2]) % mod);
	return 0;
}