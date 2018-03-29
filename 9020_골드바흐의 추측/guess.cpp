/*

2018 Mar 29, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t, v[10001] = { 0 };
	scanf("%d", &t);

	v[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		for (int j = 2; j * i <= 10000; j++) {
			v[i * j] = 1;
		}
	}

	while (t--) {
		int n, pa, pb, a, b, diff, isReturn;
		scanf("%d", &n);

		diff = 987654321;
		for (int i = 2; i <= n / 2; i++) {
			if (v[i] == 0 && v[n - i] == 0) {
				if (diff > abs(2 * i - n)) {
					diff = abs(2 * i - n);
					a = i;
					b = n - i;
				}
			}
		}

		printf("%d %d\n", a, b);

	}
	return 0;
}