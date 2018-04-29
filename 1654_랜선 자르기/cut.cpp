/*

2018 Apr 30, made by Moon

*/
#include <cstdio>
#include <vector>

using namespace std;

int n, k;
long long ans;

bool check(long long mid, vector<int> &v) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i] / mid;
	}

	return sum >= k;
}

int main() {
	scanf("%d %d", &n, &k);

	vector<int> v(n, 0);

	int maxV = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		maxV = maxV < v[i] ? v[i] : maxV;
	}

	ans = 0;

	long long l = 1;
	long long r = maxV;
	while (l <= r) {
		long long mid = (l + r) / 2;

		if (check(mid, v)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}