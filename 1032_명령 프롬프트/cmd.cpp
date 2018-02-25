/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int main() {
	int t;
	char ch[51][51];
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%s", ch[i]);
	}

	int isPattern = 0;
	for (int i = 0; ch[0][i] != '\0'; i++) {
		int j;
		for (j = 0; j < t - 1; j++) {
			if (ch[j][i] != ch[j + 1][i]) {
				isPattern = 1;
				break;
			}
		}
		if (isPattern) {
			printf("?");
		}
		else {
			if (j == 0) {
				printf("%c", ch[j][i]);
			}
			else {
				printf("%c", ch[j - 1][i]);
			}
		}
		isPattern = 0;
	}
	printf("\n");
	return 0;
}