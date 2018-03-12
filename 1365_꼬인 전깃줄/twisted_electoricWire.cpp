/*

2018 Mar 12, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int lis[100001] = { 0 };
	int v[100001] = { 0 };
	scanf("%d", &n);

	int k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		v[i] = k;
	}

	int it, size = 1;
	lis[0] = 0;
	lis[1] = 98765432;
	for (int i = 1; i <= n; i++) {
		if (v[i] > lis[size]) {
			size++;
			lis[size] = v[i];
		}
		else {
			it = lower_bound(lis, lis + size + 1, v[i]) - lis;
			lis[it] = v[i];
		}
	}
	printf("%d\n", n - size);
	return 0;
}