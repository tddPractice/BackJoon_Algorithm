/*

2018 Apr 11, made by Moon

*/
#include <cstdio>
#include <algorithm>
#define INF 999999;
using namespace std;

void floyd(int n, int x, int adj[][1001]) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int maxV = -1;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			maxV = max(maxV, adj[i][x] + adj[x][i]);
		}
	}

	printf("%d\n", maxV);
}

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	int adj[1001][1001] = { 0 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				adj[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		adj[s][e] = w;
	}

	floyd(n, x, adj);
	return 0;
}