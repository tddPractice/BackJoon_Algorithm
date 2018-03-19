/*

2018 Mar 19, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int v[502][502] = { 0 };

int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &k);
			v[i][j] = k;
		}
	}

	int maxV = 0;
	//긴 막대
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 3; j++) {
			maxV = max(maxV, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3]);
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n - 3; i++) {
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j]);
		}
	}

	//정사각형
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1]);
		}
	}

	//ㄴ 모양
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1]);
		}
		for (int j = 2; j <= m; j++) {
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j - 1]);
		}
	}
	//ㄴ 회전(90)
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			maxV = max(maxV, v[i + 1][j] + v[i][j] + v[i][j + 1] + v[i][j + 2]);
			maxV = max(maxV, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2]);
		}
	}
	
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			maxV = max(maxV, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1]);
			maxV = max(maxV, v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 2][j]);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			maxV = max(maxV, v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2] + v[i][j + 2]);
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]);
		}
	}

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1]);
			maxV = max(maxV, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j]);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			maxV = max(maxV, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2]);
			maxV = max(maxV, v[i + 1][j] + v[i + 1][j + 1] + v[i][j + 1] + v[i][j + 2]);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			maxV = max(maxV, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1]);
			maxV = max(maxV, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			maxV = max(maxV, v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1]);
			maxV = max(maxV, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1]);
		}
	}

	printf("%d\n", maxV);
	return 0;
}