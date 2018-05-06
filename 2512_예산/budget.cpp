/*

2018 May 6, made by Moon

*/
#include <cstdio>
#include <vector>

using namespace std;

int n, m, maxV;
vector<int> v;

bool check(int mid) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] <= mid) {
			sum += v[i];
		}
		else {
			sum += mid;
		}
	}

	return sum <= m && mid <= maxV;
}

int main() {
	scanf("%d", &n);

	maxV = -1;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);

		maxV = maxV < v[i] ? v[i] : maxV;
	}

	scanf("%d", &m);

	int ans = 0;
	int l = 1;
	int r = 1000000000;
	int mid;
	
	while (l <= r) {
		mid = (l + r) / 2;

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

	printf("%d\n", ans);
	return 0;
}