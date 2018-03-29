/*

2018 Mar 29, made by Moon

*/
#include <cstdio>

int main() {
	int n;
	int v[300001] = { 0 };

	v[1] = 1;
	for (int i = 2; i <= 300001; i++) {
		for (int j = 2; j * i <= 300001; j++) {
			v[i * j] = 1;
		}
	}

	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		int cnt = 0;
		for (int i = n+1; i <= n * 2; i++) {
			if (v[i] == 0) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}