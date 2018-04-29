/*

2018 Apr 29, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 1000001
using namespace std;

int n, m;
vector<int> a, b;

void merge(int start, int end) {
	int mid, i, j, k;

	mid = (start + end) / 2;
	i = start;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}

	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= end) {
		b[k++] = a[j++];
	}

	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
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

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n + m; i++) {
		a.push_back(0);
		b.push_back(0);
	}

	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i < n + m; i++) {
		scanf("%d", &a[i]);
	}

	sort(0, n + m - 1);
	for (int i = 0; i < n + m; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}