/*

2018 Mar 4, made by Moon

*/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n, k;
	int v[102][102] = { 0 };
	int check[102][102] = { 0 };
	long long dp[102][102] = { 0 };
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &k);
			v[i][j] = k;
		}
	}

	check[1][1] = 1;
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != n || j != n) {
				if (v[i][j] + i <= n && check[i][j] == 1) {
					dp[v[i][j] + i][j] += dp[i][j];
					check[v[i][j] + i][j] = 1;
				}
				if (v[i][j] + j <= n && check[i][j] == 1) {
					dp[i][v[i][j] + j] += dp[i][j];
					check[i][v[i][j] + j] = 1;
				}
			}
		}
	}

	printf("%lld\n", dp[n][n]);

	return 0;
}