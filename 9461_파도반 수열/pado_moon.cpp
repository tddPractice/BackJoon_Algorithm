/*

2018 Feb 11, made by Moon

*/
#include <cstdio>

int t;
int main() {
	scanf("%d\n", &t);

	int dp[101] = { 0, };
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	while (t--) {
		int n;
		scanf("%d", &n);
		if (n <= 5) {
			printf("%d\n", dp[n]);
		}
		else {
			for (int i = 6; i <= n; i++) {
				if (!dp[i]) {
					dp[i] = dp[i - 5] + dp[i - 1];
				}
			}
			printf("%d\n", dp[n]);
		}
	}
	return 0;
}