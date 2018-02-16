/*

2018 Feb 17, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

char s1[1001];
char s2[1002];
int dp[1002][1002] = { 0 };

int getSize() {
	int x = 0, y = 0;
	for (int i = 0; s2[i] != '\0'; i++) {
		x++;
	}
	for (int i = 0; s1[i] != '\0'; i++) {
		y++;
	}
	return dp[x][y];
}

int main() {
	scanf("%s", s1);
	scanf("%s", s2);

	for (int i = 0; s2[i] != '\0'; i++) {
		for (int j = 0; s1[j] != '\0'; j++) {
			if (s1[j] == s2[i]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	printf("%d\n", getSize());
	return 0;
}
