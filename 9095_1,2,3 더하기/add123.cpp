/*

2018 Feb 05, made by Moon

*/ 
#include <cstdio>
#include <vector>

using namespace std;

int getWays(int n) {
	int dp[12] = { 0, };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	if (n <= 3) {
		return dp[n];
	}

	for (int i = 4; i <= n; i++) {
		if (!dp[i]) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
	}
	return dp[n];
}

int main() {
	int t;
	vector<int> v;

	scanf("%d", &t);
	getchar();

	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		v.push_back(n);
		getchar();
	}

	for (int i = 0; i < t; i++) {
		int res = getWays(v[i]);
		printf("%d\n", res);
	}

	return 0;
}
