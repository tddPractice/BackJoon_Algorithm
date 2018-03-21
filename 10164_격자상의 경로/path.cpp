/*

2018 Mar 21, made by Moon

*/
#include <cstdio>

long long dp[17][17] = { 0 };
int findPath(int x1, int y1, int x2, int y2) {
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[x2][y2];
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	if (k == 0) {
		printf("%lld\n", findPath(1, 1, n, m));
	}
	else {
		int x2, y2;
		if (k % m == 0) {
			x2 = k / m;
			y2 = m;
		}
		else {
			x2 = (k / m) + 1;
			y2 = k % m;
		}
		findPath(1, 1, x2, y2);
		printf("%lld\n", findPath(x2, y2, n, m));
	}
	return 0;
}