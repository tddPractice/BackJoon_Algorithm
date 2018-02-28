/*

2018 Feb 28, made by Moon

*/
#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		char ch1[21], ch2[21];
		scanf("%s %s", ch1, ch2);

		printf("Distances: ");
		for (int i = 0; ch1[i] != '\0'; i++) {
			if (ch2[i] >= ch1[i]) {
				printf("%d ", ch2[i] - ch1[i]);
			}
			else {
				printf("%d ", (ch2[i] + 26) - ch1[i]);
			}
		}
		printf("\n");
	}
	return 0;
}