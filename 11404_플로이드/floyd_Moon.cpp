/*

2018 Apr 10, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int n = 0, m = 0, adj[101][101] = { 0 };

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &m);

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

		adj[s][e] = min(adj[s][e], w);
	}

	floyd();

	return 0;
}
