/*

2018 Apr 22, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt, last;
	scanf("%d", &n);

	vector<pair<int, int> > v;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		v.push_back(make_pair(b, a));
	}

	sort(v.begin(), v.end());

	cnt = 0;
	last = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second >= last) {
			last = v[i].first;
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}