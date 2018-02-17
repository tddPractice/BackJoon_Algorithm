/*

2018 Feb 17, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int main() {
	scanf("%d", &t);
	int k;

	while (t--) {
		scanf("%d", &k);
		int n;
		vector<vector<int> > v(2);
		vector<vector<int> > dp(2);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &n);
				v[i].push_back(n);
				dp[i].push_back(0);
			}
		}
		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		
		dp[0][1] = max(dp[0][0], dp[1][0] + v[0][1]);
		dp[1][1] = max(dp[1][0], dp[0][0] + v[1][1]);

		for (int i = 2; i < k; i++) {
			if (dp[0][i] == 0 || dp[1][i] == 0) {
				dp[0][i] = max(dp[0][i-1], dp[1][i-1] + v[0][i]);
				dp[1][i] = max(dp[1][i-1], dp[0][i-1] + v[1][i]);
			}
		}
		printf("%d\n", max(dp[0][k - 1],dp[1][k - 1]));
	}
	return 0;
}
