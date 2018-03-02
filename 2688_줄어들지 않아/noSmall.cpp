/*

2018 Mar 2, made by Moon

*/
#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);


	int dp[65][10] = { 0 };
	
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
		dp[2][i] = i + 1;
	}

	while (t--) {
		int n;
		
		scanf("%d", &n);

		for (int i = 3; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				if (!dp[i][j]) {
					for (int k = 0; k <= j; k++) {
						dp[i][j] += dp[i - 1][k];
					}
				}
			}
		}

		long long sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += dp[n][i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}