/*

2018 Mar 2, made by Moon

*/
#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	int size = 0;
	char pattern[101];
	scanf("%s", pattern);
	getchar();

	for (int i = 0; pattern[i] != '\0'; i++) {
		size++;
	}
	while (n--) {
		int chSize = 0;
		char ch[101];
		scanf("%s", ch);

		for (int i = 0; ch[i] != '\0'; i++) {
			chSize++;
		}

		if (pattern[0] == '*') {
			int i, j, flag = 1;
			for (i = size - 1, j = chSize - 1; i >= 0 && j >= 0; i--, j--) {
				if (pattern[i] != '*') {
					if (pattern[i] != ch[j]) {
						flag = 0;
						printf("NE\n");
						break;
					}
				}
			}
			if (flag) {
				printf("DA\n");
			}
		}
		else if (pattern[size - 1] == '*') {
			int i, flag = 1;
			for (i = 0; pattern[i] != '*' && ch[i] != '\0'; i++) {
				if (ch[i] != pattern[i]) {
					flag = 0;
					break;
				}
			}
			if (i == chSize && flag == 1) {
				printf("DA\n");
			}
			else if (flag == 1) {
				printf("DA\n");
			}
			else if (flag == 0) {
				printf("NE\n");
			}
		}
		else {
			int i, flag = 1, pos;
			for (i = 0; pattern[i] != '*'; i++) {
				if (ch[i] != pattern[i] || ch[i] == '\0') {
					flag = 0;
					break;
				}
			}
			pos = i - 1;

			if (flag) {
				int j;
				for (i = size - 1, j = chSize - 1; pattern[i] != '*' && ch[j] != '\0'; i--, j--) {
					if (pos == j || ch[j] != pattern[i] || ch[j] == '\0') {
						flag = 0;
						break;
					}
				}
			}

			if (flag) {
				printf("DA\n");
			}
			else {
				printf("NE\n");
			}
		}
	}
	return 0;
}