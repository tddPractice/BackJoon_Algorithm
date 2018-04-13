/*

2018 Apr 13, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 99999999
using namespace std;

void floyd(int n, vector<vector<int> > &adj) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int minV = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			minV = min(minV, adj[i][j] + adj[j][i]);
		}
	}

	if (minV == INF) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", minV);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int> > adj(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= m; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		adj[s][e] = w;
	}

	floyd(n, adj);

	return 0;
}