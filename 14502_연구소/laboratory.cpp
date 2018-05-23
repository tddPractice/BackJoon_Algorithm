/*

201 May 23, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10
using namespace std;

int n, m, ans;
int v[MAX][MAX];

void bfs() {
	int tmp[MAX][MAX];
	int visited[MAX][MAX];
	int x[4] = { 0, 0, 1, -1 };
	int y[4] = { 1, -1, 0, 0 };

	queue<pair<int, int> > q;

	if (v[1][5] == 1 && v[2][4] == 1 && v[4][4] == 1) {
		int a = 1;
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tmp[i][j] = v[i][j];
			visited[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tmp[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				if (tmp[curX + x[k]][curY + y[k]] == 0 && visited[curX + x[k]][curY + y[k]] == 0) {
					tmp[curX + x[k]][curY + y[k]] = 2;
					visited[curX + x[k]][curY + y[k]] = 1;
					q.push(make_pair(curX + x[k], curY + y[k]));
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}

	ans = max(ans, cnt);
}

void start() {
	int checked[MAX][MAX];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == 0) {
				v[i][j] = 1;

				for (int ii = 1; ii <= n; ii++) {
					for (int jj = 1; jj <= m; jj++) {
						if (v[ii][jj] == 0 ) {
							v[ii][jj] = 1;

							for (int p = 1; p <= n; p++) {
								for (int q = 1; q <= m; q++) {
									if (v[p][q] == 0) {
										v[p][q] = 1;
										bfs();
										v[p][q] = 0;
									}
								}
							}

							v[ii][jj] = 0;
						}
					}
				}

				v[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			v[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	ans = 0;
	start();

	printf("%d\n", ans);
	return 0;
}