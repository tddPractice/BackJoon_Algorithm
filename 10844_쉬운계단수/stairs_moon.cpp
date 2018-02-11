/*

2018 Feb 11, made by Moon

*/
#include <cstdio>

int n;

int main() {
	scanf("%d", &n);
	long long acc = 0;
	long long dp[101][101] = { 0, };

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= 9; i++) {
		if (i == 9)
			dp[2][i] = 1;
		else
			dp[2][i] = 2;
	}
	if (n <= 2) {
		printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5]
			+ dp[n][6] + dp[n][7] + dp[n][8] + dp[n][9]);
		return 0;
	}

	for (int i = 3; i <= n; i++) {
		dp[i][1] = ((dp[i - 1][2] % 1000000000) + (dp[i - 2][1] % 1000000000)) % 1000000000;
		for (int j = 2; j <= 8; j++) {
			dp[i][j] = ((dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000)) % 1000000000;
		}
		dp[i][9] = ((dp[i - 2][7] % 1000000000) + (dp[i - 2][9] % 1000000000)) % 1000000000;
	}

	for (int i = 1; i <= 9; i++) {
		acc = (acc + dp[n][i]) % 1000000000;
	}
	printf("%lld\n", acc % 1000000000);
	return 0;
}