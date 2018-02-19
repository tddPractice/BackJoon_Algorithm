/*

2018 Feb 19, made by Moon

*/
#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);

	int n;
	long long dp[70] = { 0 };

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t--) {
		scanf("%d", &n);

		for (int i = 4; i <= n; i++) {
			if (!dp[i])
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
		}

		printf("%lld\n", dp[n]);
	}
	return 0;
}
