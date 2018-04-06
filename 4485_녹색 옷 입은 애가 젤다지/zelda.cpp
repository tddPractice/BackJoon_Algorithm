/*

2018 Apr 6, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };

void dfs(int i, int j, vector<vector<int> > &adj, vector<vector<int> > &v, vector<vector<int> > &visited) {
	visited[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		if (v[i + x[k]][j + y[k]] >= 0 && adj[i + x[k]][j + y[k]] > adj[i][j] + v[i + x[k]][j + y[k]]) {
			
			adj[i + x[k]][j + y[k]] = adj[i][j] + v[i + x[k]][j + y[k]];
			
			if (visited[i + x[k]][j + y[k]] == 1) {
				dfs(i + x[k], j + y[k], adj, v, visited);
			}
		}
	}
}

void dfsAll(int cnt, int n, vector<vector<int> > &adj, vector<vector<int> > &v, vector<vector<int> > &visited) {
	
	adj[1][1] = v[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j, adj, v, visited);
			}
		}
	}

	printf("Problem %d: %d\n", cnt, adj[n][n]);
}

int main() {
	int cnt = 1;

	while (true) {
		int n, k;
		scanf("%d", &n);

		if (n == 0) {
			break;
		}
		else {
			vector<vector<int> > adj(n + 2, vector<int>(n + 2, 9999));
			vector<vector<int> > v(n + 2, vector<int>(n + 2, -1));
			vector<vector<int> > visited(n + 2, vector<int>(n + 2, 0));

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					scanf("%d", &k);
					v[i][j] = k;
				}
			}

			dfsAll(cnt, n, adj, v, visited);
			cnt++;
		}
	}
	return 0;
}