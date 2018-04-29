/*

2018 Apr 30, made by Moon

*/
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

bool check(long long mid) {
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] > mid) {
			sum += v[i] - mid;
		}
	}

	return sum >= m;
}

int main() {
	scanf("%d %d", &n, &m);

	int maxV = -1;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);

		if (maxV < k) {
			maxV = k;
		}
	}

	long long l = 1;
	long long r = maxV;
	long long ans = 0;

	while (l <= r) {
		long long mid = (l + r) / 2;

		if (check(mid)) {
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