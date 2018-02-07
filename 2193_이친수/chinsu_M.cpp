/*

2018 Feb 07, made by Moon

*/
#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	long long dp[91] = { 0, 1, 1, 2,  };
	for (int i = 4; i <= n; i++) {
		if (!dp[n]) {
			long long sum = 0;
			for (int j = i - 2; j >= 1; j--) {
				sum += dp[j];
			}
			dp[i] = sum + 1;
		}
	}
  printf("%lld\n", dp[n]);
	return 0;
}
