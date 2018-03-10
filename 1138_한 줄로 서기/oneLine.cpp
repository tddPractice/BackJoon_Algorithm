/*

2018 Mar 10, made by Moon

*/
#include <cstdio>

int main() {
	int n;
	int line[11] = { 0 };
	scanf("%d", &n);

	int k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (line[j] == 0) {
				if (cnt == k) {
					line[j] = i + 1;
					break;
				}
				else {
					cnt++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", line[i]);
	}
	printf("\n");
	return 0;
}