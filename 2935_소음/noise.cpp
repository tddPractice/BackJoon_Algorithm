/*

2018 Apr 16, made by Moon

*/
#include <cstdio>

int main() {
	char a[101], b[101], oper;

	scanf("%s", a);
	getchar();
	scanf("%c", &oper);
	getchar();
	scanf("%s", b);

	if (oper == '*') {
		printf("%s", a);

		for (int i = 1; b[i] != '\0'; i++) {
			printf("%c", b[i]);
		}
		printf("\n");
	}
	else if (oper == '+') {
		int c[101] = { 0 };
		int sizeA = 0, sizeB = 0;

		for (int i = 0; a[i] != '\0'; i++) {
			sizeA++;
		}
		for (int i = 0; b[i] != '\0'; i++) {
			sizeB++;
		}

		if (sizeA > sizeB) {
			for (int i = 0; a[i] != '\0'; i++) {
				c[i] = a[i] - '0';
			}

			for (int i = sizeB - 1, j = sizeA - 1; i >= 0; i--, j--) {
				c[j] += b[i] - '0';
			}

			for (int i = 0; i < sizeA; i++) {
				printf("%d", c[i]);
			}
			printf("\n");
		}
		else {
			for (int i = 0; b[i] != '\0'; i++) {
				c[i] = b[i] - '0';
			}

			for (int i = sizeA - 1, j = sizeB - 1; i >= 0; i--, j--) {
				c[j] += a[i] - '0';
			}

			for (int i = 0; i < sizeB; i++) {
				printf("%d", c[i]);
			}
			printf("\n");
		}
	}

	return 0;
}