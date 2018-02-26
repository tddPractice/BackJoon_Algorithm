/*

2018 Feb 26, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	char ch[101];
	char ch2[101];
	while (~scanf("%s", ch)) {
		int lcs[102][102] = { 0 };
		scanf("%s", ch2);

		int i, j;
		for (i = 0; ch[i] != '\0'; i++) {
			for (j = 0; ch2[j] != '\0'; j++) {
				if (ch[i] == ch2[j]) {
					lcs[i + 1][j + 1] = lcs[i][j] + 1;
				}
				else {
					lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
				}
			}
		}

		printf("%d\n", lcs[i][j]);
	}
	return 0;
}