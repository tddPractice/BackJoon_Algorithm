#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 10001
using namespace std;

int n, m;
vector<int> v;

void merge(int start, int end) {
	int l, r, i, j, mid, k;

	mid = (start + end) / 2;
	i = start;
	j = mid + 1;
	k = 0;

	int tmp[MAX] = { 0 };

	while (i <= mid && j <= end) {
		if (v[i] < v[j]) {
			tmp[k++] = v[i++];
		}
		else {
			tmp[k++] = v[j++];
		}
	}

	while (i <= mid) {
		tmp[k++] = v[i++];
	}
	while (j <= end) {
		tmp[k++] = v[j++];
	}

	for (int i = start; i <= end; i++) {
		v[i] = tmp[i - start];
	}
}

void sort(int start, int end) {
	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;

	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}

int find(int k) {
	int l = 0;
	int r = n - 1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (k < v[mid]) {
			r = mid - 1;
		}
		else if (k > v[mid]) {
			l = mid + 1;
		}
		else {
			return 1;
		}
	}

	return 0;
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}

	//sort(0, n - 1);
	sort(v.begin(), v.end());

	scanf("%d", &m);

	for(int i = 1; i <= m; i++) {
		int k;
		scanf("%d", &k);

		printf("%d\n", find(k));
	}

	return 0;
}