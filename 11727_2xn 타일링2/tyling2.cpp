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
	dp[2] = 3;
	dp[3] = 5;

	for (int i = 4; i <= n; i++) {
		if (!dp[i]) {
			dp[i] = ((((dp[i - 2]) % size) * 3) % size + ((dp[i - 3] % size) * 2) % size) % size;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
