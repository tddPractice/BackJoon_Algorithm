/*

2018 Mar 30, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

void dfs(int n, vector<int> &visited, vector<vector<int> > &path, vector<vector<int> > &adj, int root) {
	visited[n] = 1;
	for (int i = 0; i < adj[n].size(); i++) {
		if (!visited[adj[n][i]]) {
			path[root][adj[n][i]] = -1;
			path[adj[n][i]][root] = 1;
			dfs(adj[n][i], visited, path, adj, root);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int> > path(n + 1, vector<int>(n + 1, 0));
	vector<vector<int> > adj(n + 1, vector<int>());

	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
	}

	for (int i = 1; i <= n; i++) {
		vector<int> visited(n + 1, 0);
		dfs(i, visited, path, adj, i);
	}

	int t;
	scanf("%d", &t);

	while (t--) {
		int s, e;
		scanf("%d %d", &s, &e);

		if (path[s][e] == -1) {
			printf("-1\n");
		}
		else {
			if (path[e][s] == -1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}
	return 0;
}