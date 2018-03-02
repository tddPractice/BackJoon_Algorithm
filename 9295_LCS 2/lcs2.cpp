/*

2018 Mar 3, made by Moond

*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<char> v;
	char ch1[1001];
	char ch2[1001];
	int dp[1002][1002] = { 0 };

	scanf("%s", ch1);
	scanf("%s", ch2);

	int i, j;
	for (i = 0; ch1[i] != '\0'; i++) {
		for (j = 0; ch2[j] != '\0'; j++) {
			if (ch1[i] == ch2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	printf("%d\n", dp[i][j]);
	for (int x = i; x >= 1; x--) {
		for (int y = j; y >= 1; y--) {
			if (dp[x][y] != dp[x][y - 1]) {
				if (dp[x][y] != dp[x - 1][y]) {
					v.push_back(ch1[x - 1]);
					j = y;
					break;
				}
				else {
					break;
				}
			}
		}
	}
	for (int x = v.size() - 1; x >= 0; x--) {
		printf("%c", v[x]);
	}
	printf("\n");

	return 0;
}