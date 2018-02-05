/*

2018 Feb 05, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void getScore(int n, vector<int> c) {
	int dp[301] = { 0, };

	dp[0] = c[0];
	dp[1] = c[0] + c[1];
	dp[2] = max(c[0] + c[2], c[1] + c[2]);

	int i;
	for (i = 3; i < n; i++) {
		if (!dp[i]) {
			dp[i] = max(dp[i-3] + c[i-1] + c[i], dp[i-2] + c[i]);
		}
	}

	printf("%d\n", dp[i - 1]);
}

int main() {
	vector<int> c;
	int n;
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		int score;
		scanf("%d", &score);
		c.push_back(score);
		getchar();
	}

	getScore(n, c);

	return 0;
}
