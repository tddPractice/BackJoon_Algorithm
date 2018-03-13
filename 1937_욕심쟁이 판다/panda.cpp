/*

2018 Mar 13, made by Moon

*/
#include <cstdio>

int v[502][502] = { 0 }, dp[502][502] = { 0 };
int x[4] = { -1, 0, 0, 1 };
int y[4] = { 0, -1, 1, 0 };

void checkValue(int i, int j) {
	for (int k = 0; k < 4; k++) {
		if (v[i + x[k]][j + y[k]] > 0) {
			if (v[i][j] < v[i + x[k]][j + y[k]]) {
				if (dp[i][j] + 1 > dp[i + x[k]][j + y[k]]) {
					dp[i + x[k]][j + y[k]] = dp[i][j] + 1;
					checkValue(i + x[k], j + y[k]);
				}
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int k;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			scanf("%d", &k);
			v[i][j] = k;
			dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (k = 0; k < 4; k++) {
				if (v[i + x[k]][j + y[k]] > 0){
					if (v[i][j] < v[i + x[k]][j + y[k]]) {
						if (dp[i][j] + 1 > dp[i + x[k]][j + y[k]]) {
							dp[i + x[k]][j + y[k]] = dp[i][j] + 1;
							checkValue(i + x[k], j + y[k]);
						}
					}
				}
			}
		}
	}

	int maxV = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			maxV = dp[i][j] > maxV ? dp[i][j] : maxV;
		}
	}


	printf("%d\n", maxV);
	return 0;
}