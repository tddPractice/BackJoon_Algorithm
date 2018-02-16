/*

2018 Feb 17, made by Moon

*/
#include <cstdio>

int t;
int main() {
	scanf("%d", &t);
	int n, k;
	int dp[101][101][2] = { 0 };
	
	dp[2][0][0] = 2;
	dp[2][0][1] = 1;
	dp[2][1][0] = 0;
	dp[2][1][1] = 1;

	dp[3][0][0] = 3;
	dp[3][0][1] = 2;
	dp[3][1][0] = 1;
	dp[3][1][1] = 1;
	dp[3][2][0] = 0;
	dp[3][2][1] = 1;
	
	while (t--) {
		scanf("%d %d", &n, &k);

		for (int j = 4; j <= n; j++) {
			for (int i = 0; i < n; i++) {
				if (!dp[j][i][0] || dp[j][i][1]) {
					dp[j][i][0] = dp[j - 1][i][0] + dp[j - 1][i][1];
					if (i == 0) {
						dp[j][i][1] = dp[j - 1][0][0];
					}
					else {
						dp[j][i][1] = dp[j - 1][i][0] + dp[j - 1][i - 1][1];
					}
				}
			}
		}

		printf("%d\n", dp[n][k][0] + dp[n][k][1]);
	}
	return 0;
}
