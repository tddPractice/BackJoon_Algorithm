/*

2018 Mar 20, made by Moon

*/
#include <cstdio>

int main() {
	int n, k, dp[11] = { 0 };
	scanf("%d %d", &n, &k);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 10; i++) {
		if (!dp[i]) {
			dp[i] = dp[i - 1] * i;
		}
	}

	printf("%d\n", dp[n] / (dp[n - k] * dp[k]));
	return 0;
}