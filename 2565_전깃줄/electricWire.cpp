/*

2018 Mar 12, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int a, b;
	int v[501] = { 0 };

	for (int i = 0; i < 501; i++) {
		v[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[a] = b;
	}

	int lis[501] = { 0 }, size = 1;
	lis[1] = 98765432;
	for (int i = 1; i < 501; i++) {
		if (v[i] != 0) {
			int it = lower_bound(lis, lis + size, v[i]) - lis;
			if (v[i] < lis[it]) {
				lis[it] = v[i];
			}
			else {
				size++;
				lis[size] = v[i];
			}
		}
	}

	printf("%d\n", n - size);
	return 0;
}