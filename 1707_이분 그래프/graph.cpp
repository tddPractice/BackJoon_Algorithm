/*

2018 Apr 28, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 200002
using namespace std;

int t, n, m;

bool bfs(int root, vector<vector<int> > &adj, vector<int> &color) {
	int c = 1;
	queue<int> q;
	q.push(root);
	color[root] = c;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int r = q.front();
			q.pop();
			c = -color[r];

			for (auto j : adj[r]) {
				if (color[j] == 0) {
					q.push(j);
					color[j] = c;
				}
				else {
					if (color[j] == color[r]) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main() {
	scanf("%d", &t);

	vector<vector<int> > adj(MAX, vector<int>());
	vector<int> color(MAX, 0);

	while (t--) {
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int fail = 0;
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				if (!bfs(i, adj, color)) {
					fail = 1;
					break;
				}
			}
		}

		if (fail) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}

		for (int i = 1; i <= n; i++) {
			color[i] = 0;
			vector<int>().swap(adj[i]);
		}
	}

	return 0;
}