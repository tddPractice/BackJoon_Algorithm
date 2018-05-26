/*

2018 Apr 8, made by Moon

Edited
2018 Mary 26, made by Moon
*/
#include <cstdio>
#include <algorithm>

#define MAX 101
#define INF 99999999
using namespace std;

int n, m;
int adj[MAX][MAX];

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
			if (adj[i][j] != INF) {
				printf("%d ", adj[i][j]);
			}
			else {
				printf("%d ", 0);
			}
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				adj[i][j] = 0;
			}
			else {
				adj[i][j] = INF;
			}
		}
	}

	while (m--) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		adj[s][e] = min(adj[s][e], w);
	}

	floyd();

	return 0;
}