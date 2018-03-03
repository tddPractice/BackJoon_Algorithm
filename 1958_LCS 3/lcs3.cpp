/*

2018 Mar 4, made by Moon

*/
#include <cstdio>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	char ch1[101], ch2[101], ch3[101];
	int lcs[102][102][102] = { 0 };
	int i, j, k;

	scanf("%s", ch1);
	scanf("%s", ch2);
	scanf("%s", ch3);

	for (i = 0; ch1[i] != '\0'; i++) {
		for (j = 0; ch2[j] != '\0'; j++) {
			for (k = 0; ch3[k] != '\0'; k++) {
				if ((ch1[i] == ch2[j]) &&(ch2[j] == ch3[k]) && (ch1[i] == ch3[k])) {
					lcs[i + 1][j + 1][k + 1] = lcs[i][j][k] + 1;
				}
				else {
					lcs[i + 1][j + 1][k + 1] = max(lcs[i][j + 1][k + 1], max(lcs[i + 1][j][k + 1], lcs[i + 1][j + 1][k]));
				}
			}
		}
	}

	printf("%d\n", lcs[i][j][k]);
	return 0;
}