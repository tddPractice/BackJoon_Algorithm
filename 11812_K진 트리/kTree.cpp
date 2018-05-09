/*

2018 May 4, made by Moon

*/
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long n, k, q;
map<int, int> m;

long long getDist(long long x, long long y) {
	long long hx, hy, h, hCnt, commH;
	long long top, bot, comm;

	if (m[x]) {
		hx = m[x];
	}
	else {
		if (x <= 2) {
			hx = x - 1;
		}
		else {
			h = k;
			hCnt = 2;
			for (long long i = 2;; i += h, h *= k, hCnt++) {
				if (x < i + h) {
					hx = hCnt - 1;
					break;
				}
			}
		}
		m[x] = hx;
	}

	if (m[y]) {
		hy = m[y];
	}
	else {
		if (y <= 2) {
			hy = y - 1;
		}
		else {
			h = k;
			hCnt = 2;
			for (long long i = 2;; i += h, h *= k, hCnt++) {
				if (y < i + h) {
					hy = hCnt - 1;
					break;
				}
			}
		}
		m[y] = hy;
	}

	if (hx > hy) {
		for (int i = hy; i < hx; i++) {
			x = (x + k - 2) / k;
		}
	}
	else {
		for (int i = hx; i < hy; i++) {
			y = (y + k - 2) / k;
		}
	}


	while (x != y) {
		x = (x + k - 2) / k;
		y = (y + k - 2) / k;
	}

	comm = x;
	if (comm <= 2) {
		commH = comm - 1;
	}
	else {
		h = k;
		hCnt = 2;
		for (long long i = 2;; i += h, h *= k, hCnt++) {
			if (comm < i + h) {
				commH = hCnt - 1;
				break;
			}
		}
	}

	return abs(hx - commH) + abs(hy - commH);
}

int main() {
	scanf("%lld %lld %lld", &n, &k, &q);

	vector<pair<long long, long long> > v;
	for (int i = 1; i <= q; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);

		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i < v.size(); i++) {
		if (k == 1) {
			printf("%lld\n", abs(v[i].first - v[i].second));
		}
		else {
			printf("%lld\n", getDist(v[i].first, v[i].second));
		}
	}
	return 0;
}