/*

2018 May 7, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
vector<int> v, b;
map<int, int> mp;

int find(int k, vector<int> &t) {
	int size = t.size() - 1;
	int l = 0;
	int r = size;
	int mid;
	int ans = 0;

	while (l <= r) {
		mid = (l + r) / 2;
		
		if (k < t[mid]) {
			r = mid - 1;
		}
		else if (k > t[mid]) {
			l = mid + 1;
		}
		else if (k == t[mid]) {
			int j = mid;
			while (j >= 0 && t[j] == k) {
				ans++;
				j--;
			}

			j = mid + 1;
			while (j <= size && t[j] == k) {
				ans++;
				j++;
			}
			break;
		}
	}

	return ans;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);

		if (k >= 0) {
			v.push_back(k);
		}
		else {
			b.push_back(-k);
		}
	}

	sort(v.begin(), v.end());
	sort(b.begin(), b.end());

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int k, ans;
		scanf("%d", &k);

		if (mp[k] == 0) {
			if (k >= 0) {
				ans = find(k, v);
			}
			else {
				ans = find(-k, b);
			}
			mp[k] = ans;
			printf("%d ", ans);
		}
		else {
			printf("%d ", mp[k]);
		}
	}
	printf("\n");

	return 0;
}