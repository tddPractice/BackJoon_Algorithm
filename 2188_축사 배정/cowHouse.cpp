/*

2018 Apr 27, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 201
#define INF 9999999
using namespace std;

int n, m;
int l[MAX], r[MAX], visited[MAX];
vector<int> adj[MAX];

bool dfs(int k) {
	visited[k] = 1;

	for (auto i : adj[k]) {
		if (r[i] == -1 || !visited[r[i]] && dfs(r[i])) {
			l[k] = i;
			r[i] = k;
			return true;
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);

		for (int j = 1; j <= k; j++) {
			int t;
			scanf("%d", &t);
			adj[i].push_back(t);
		}
	}

	int match = 0;
	fill(l, l + MAX, -1);
	fill(r, r + MAX, -1);

	for (int i = 1; i <= n; i++) {
		if (l[i] == -1) {
			fill(visited, visited + MAX, 0);
			if (dfs(i)) {
				match++;
			}
		}
	}

	printf("%d\n", match);
	return 0;
}
