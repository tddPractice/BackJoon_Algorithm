/*

2018 May 11, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void find(vector<pair<int, int> > &v) {
	long long l = 0;
	long long r = 2000000000000000;
	long long mid;

	while (l <= r) {
		mid = (l + r) / 2;

		long long sn = m;
		for (int i = 0; i < m; i++) {
			sn += mid / v[i].first;
		}

		long long cnt = 0;
		for (int i = 0; i < m; i++) {
			if (mid % v[i].first == 0) {
				cnt++;
			}
		}

		if (sn >= n && n > sn - cnt) {
			long long sub = sn - cnt + 1;

			for (int i = 0; i < m; i++) {
				if (mid % v[i].first == 0) {
					if (sub == n) {
						printf("%d\n", v[i].second);
						return;
					}
					sub++;
				}
			}
		}
		else if (sn < n) {
			l = mid + 1;
		}
		else if (sn - cnt >= n) {
			r = mid - 1;
		}
	}

}

int main() {
	scanf("%d %d", &n, &m);
		
	vector<pair<int, int> > v;

	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(make_pair(k, i + 1));
	}

	find(v);

	return 0;
}