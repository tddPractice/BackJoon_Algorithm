/*

2018 Apr 14, made by Moon

*/
#include <cstdio>

int main() {
	char ch[5] = { 'D', 'C', 'B', 'A', 'E' };
	for(int t = 0; t < 3; t++) {
		int i, n, cnt;
		for (i = 1, cnt = 4; i <= 4; i++) {
			scanf("%d", &n);

			if (n == 0) {
				cnt--;
			}
		}

		printf("%c\n", ch[cnt]);
	}
	return 0;
}