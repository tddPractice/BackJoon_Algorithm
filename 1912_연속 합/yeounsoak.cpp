/*

2018 Feb 11, made by Moon

*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
	
	int t;
	vector<int> v;
	vector<int> dp;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		v.push_back(t);
	}

	if (n == 1) {
		printf("%d\n", v[1]);
		return 0;
	}
	dp.push_back(0);
	dp.push_back(v[1]);
	dp.push_back(max(v[1], max(v[2], v[1] + v[2])));
	for (int i = 3; i <= n; i++) {
		dp.push_back(max(v[i], v[i] + dp[i-1]));
	}

	int maxVal = -98765432;
	for (int i = 1; i < dp.size(); i++) {
		maxVal = max(maxVal, dp[i]);
		//printf("dp[%d]: %d\n", i, dp[i]);
	}

	printf("%d\n", maxVal);
	return 0;
}
