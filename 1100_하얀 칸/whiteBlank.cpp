/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int main() {
	char ch[9][9];

	for (int i = 0; i < 8; i++) {
		scanf("%s", ch[i]);
	}

	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (ch[i][j] == 'F') {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						cnt++;
					}
				}
				else {
					if (j % 2 == 1) {
						cnt++;
					}
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}