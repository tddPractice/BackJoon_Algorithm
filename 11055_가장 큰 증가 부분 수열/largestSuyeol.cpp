/*

2018 Feb 18, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> dp;
int main() {
	scanf("%d", &n);

	int k;
	v.push_back(0);
	dp.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		v.push_back(k);
		dp.push_back(0);
	}

	int maxS;
	dp[n] = v[n];
	for (int i = v.size() - 1; i >= 1; i--) {
		maxS = v[i];
		for (int j = i + 1; j <= n; j++) {
			if(v[j] > v[i])
				maxS = max(v[i] + dp[j], maxS);
		}
		dp[i] = maxS;
	}

	maxS = 0;
	for (int i = 1; i <= n; i++) {
		maxS = max(maxS, dp[i]);
	}
	printf("%d\n", maxS);
}
