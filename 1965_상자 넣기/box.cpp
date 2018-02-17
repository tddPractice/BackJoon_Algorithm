/*

2018 Feb 18, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main() {
	scanf("%d", &n);

	int k;
	vector<int> v;
	vector<int> dp;

	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			v.push_back(0);
		}
		else {
			scanf("%d", &k);
			v.push_back(k);
		}
		dp.push_back(0);
	}

	int maxS;
	for (int i = v.size() - 1; i >= 1; i--) {
		maxS = 0;
		for (int j = i + 1; j <= n; j++) {
			if (v[i] < v[j]) {
				maxS = max(dp[j], maxS);
			}
		}
		dp[i] = ++maxS;
	}

	maxS = 0;
	for (int i = 1; i <= n; i++) {
		maxS = max(dp[i], maxS);
	}
	printf("%d\n", maxS);
	return 0;
}
