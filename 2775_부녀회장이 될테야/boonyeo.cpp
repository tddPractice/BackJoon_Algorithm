/*

2018 Feb 12, made by Moon

*/
#include <cstdio>

int n, k, t;
int main() {
	int dp[15][15] = { 0 };
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= 14; i++) {
			dp[0][i] = i;
		}

		int sum = 0;
		for (int i = 1; i <= 14; i++) {
			for (int j = 1; j <= 14; j++) {
				sum = 0;
				for (int k = 1; k <= j; k++) {
					sum += dp[i-1][k];
				}
				dp[i][j] = sum;
			}
		}

		printf("%d\n", dp[n][k]);
	}
	return 0;
}
