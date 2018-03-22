/*

2018 Mar 22, made by Moon

*/
#include <cstdio>

int main() {
	int t, n, k;
	scanf("%d", &t);

	while (t--) {
		double sum = 0.0, aver = 0.0, tot = 0.0;
		int avg[1001] = { 0 };
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &k);
			avg[i] = k;
			sum += k;
		}
		aver = sum / n;

		for (int i = 0; i < n; i++) {
			if (avg[i] > aver) {
				tot++;
			}
		}
		printf("%.3f%%\n", (tot / n) * 100);
	}
	return 0;
}