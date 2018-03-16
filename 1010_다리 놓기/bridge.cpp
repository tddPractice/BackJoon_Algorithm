/*

2018 Mar 17, made by Moon

*/
#include <cstdio>

int main() {
	int t, a, b;
	int dp[31][31] = { 0 };
	scanf("%d", &t);

	//dp[1][i], dp[2][i] √ ±‚»≠
	for (int i = 1; i < 30; i++) {
		dp[1][i] = i;
		for (int j = 1; j < i; j++) {
			dp[2][i] += j;
		}
	}

	for (int i = 3; i < 30; i++) {
		for (int j = 1; j < 30; j++) {
			if (!dp[i][j]) {
				for (int k = j-1; k >= 1; k--) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}