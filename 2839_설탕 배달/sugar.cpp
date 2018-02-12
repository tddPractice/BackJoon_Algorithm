/*

2018 Feb 12, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int dp[5001];
	scanf("%d", &n);

	for (int i = 0; i < 5001; i++) {
		dp[i] = -1;
	}

	dp[3] = 1;
	dp[5] = 1;
	
	for (int i = 6; i <= n; i++) {
		if (dp[i] == -1) {
			if (dp[i - 3] == -1) {
				if (dp[i - 5] == -1) {
					dp[i] = -1;
				}
				else {
					dp[i] = dp[i - 5] + 1;
				}
			}
			else if (dp[i - 5] == -1) {
				if (dp[i - 3] == -1) {
					dp[i] = -1;
				}
				else {
					dp[i] = dp[i - 3] + 1;
				}
			}
			else if (dp[i - 3] != -1 && dp[i - 5] != -1) {
				dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
			}
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
