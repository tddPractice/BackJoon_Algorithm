/*

2018 Mar 13, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int k, it, n, size;
	char cInt;
	while (scanf("%d", &n) != EOF) {

		size = 1;
		int lis[100001] = { 0 };
		lis[0] = - 1;
		lis[1] = 987654321;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &k);
			if (lis[size] < k) {
				lis[++size] = k;
			}
			else {
				it = lower_bound(lis, lis + size + 1, k) - lis;
				lis[it] = k;
			}
		}
		printf("%d\n", size);
	}
	return 0;
}