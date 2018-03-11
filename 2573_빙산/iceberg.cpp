/*

2018 Mar 11, made by Moon

*/
#include <cstdio>

int n, m, cnt = 0;
int x[4] = { -1, 0, 1, 0 };
int y[4] = { 0, 1, 0, -1 };
int v[302][302] = { 0 };
int visited[302][302] = { 0 };

void dfs(int a, int b) {
	visited[a][b] = 1;


	for (int k = 0; k < 4; k++) {
		if (v[a + x[k]][b + y[k]] == 0 && visited[a + x[k]][b + y[k]] == 0) {
			if (v[a][b] - 1 == 0) {
				cnt--;
			}
			if (v[a][b] - 1 >= 0) {
				v[a][b]--;
			}
		}
	}

	for (int k = 0; k < 4; k++) {
		if (visited[a + x[k]][b + y[k]] == 0 && v[a + x[k]][b + y[k]] > 0) {
			dfs(a + x[k], b + y[k]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			v[i][j] = -1;
		}
	}

	int k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &k);
			v[i][j] = k;
			if (k > 0) {
				cnt++;
			}
		}
	}

	int year = 0;
	
	while (true) {
		int firstLoop = 0;
		if (cnt <= 0 && firstLoop == 0) {
			printf("0\n");
			break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (visited[i][j] == 0 && v[i][j] > 0) {
					if (!firstLoop) {
						dfs(i, j);
						year++;
						firstLoop = 1;
					}
					else {
						printf("%d\n", year - 1);
						return 0;
					}
				}
			}
		}


		for (int ix = 1; ix <= n; ix++) {
			for (int jx = 1; jx <= m; jx++) {
				visited[ix][jx] = 0;
			}
		}
	}
	return 0;
}