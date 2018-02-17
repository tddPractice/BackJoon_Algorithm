/*

2018 Feb 18, made by Moon

*/
#include <cstdio>

int main() {
	int n, size = 10007;
	int dp[1001][10] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += (dp[i - 1][k]) % size;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res = (res + dp[n][i] % size) % size;
	}
	printf("%d\n", res);
}
