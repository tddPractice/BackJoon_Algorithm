/*

2018 Feb 17, made by Moon

*/
#include <cstdio>

int n;
int main() {
	scanf("%d", &n);

	int size = 10007;
	int dp[1001] = { 0 };
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		if (!dp[i]) {
			dp[i] = (dp[i - 1] % size + dp[i - 2] % size) % size;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
