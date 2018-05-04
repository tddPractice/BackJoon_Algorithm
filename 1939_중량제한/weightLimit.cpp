/*

2018 May 3, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001
#define INF 1000000001
using namespace std;

int n, m, s, e;
int ans = -1;
vector<vector<int> > adj(MAX, vector<int>()); 
vector<vector<int> > w(MAX, vector<int>());
int visited[MAX];

bool bfs(int r, int limit) {
	queue<int> q;
	q.push(r);
	visited[r] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == e) {
			return true;
		}

		for (int i = 0; i < adj[cur].size(); i++) {
			if (!visited[adj[cur][i]] && w[cur][i] >= limit) {
				q.push(adj[cur][i]);
				visited[adj[cur][i]] = 1;
			}
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(b);
		adj[b].push_back(a);

		w[a].push_back(c);
		w[b].push_back(c);
	}

	scanf("%d %d", &s, &e);

	int l = 1;
	int r = 1e9;
	int mid;
	int ans = 0;

	while (l <= r) {
		mid = l + (r - l) / 2;
		if (mid == 3) { 
			int a = 1;
		}
		fill(visited, visited + MAX, 0);

		if (bfs(s, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}