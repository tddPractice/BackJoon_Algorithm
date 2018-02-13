/*

2018 Feb 12, made by Moon

*/
#include <cstdio>

int t;

bool findN(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			cnt++;
	}
	if (cnt % 2 == 0)
		return true;
	else
		return false;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		int dp[101] = { 0 };
		scanf("%d", &n);

		dp[5] = 2;
		for (int i = 6; i <= n; i++) {
			if (findN(i))
				dp[i] = dp[i - 1];
			else
				dp[i] = dp[i - 1] + 1;
		}
		printf("%d\n", dp[n]);
	}

	return 0;
}
