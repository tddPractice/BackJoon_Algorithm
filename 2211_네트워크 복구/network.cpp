/*

2018 Apr 12, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

void djikstra(int n, vector<vector<pair<int, int> > > &adj, vector<int> &dist, vector<int> &path) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 1));
	dist[1] = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int w = q.top().first;
			int v = q.top().second;
			q.pop();

			for (int j = 0; j < adj[v].size(); j++) {
				if (dist[adj[v][j].first] > dist[v] + adj[v][j].second) {
					dist[adj[v][j].first] = dist[v] + adj[v][j].second;
					q.push(make_pair(-dist[adj[v][j].first], adj[v][j].first));

					path[adj[v][j].first] = v;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (path[i] != INF) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	for (int i = 1; i <= n; i++) {
		if (path[i] != INF) {
			printf("%d %d\n", path[i], i);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<pair<int, int> > > adj(n + 1, vector<pair<int, int> >());
	vector<int> dist(n + 1, INF);
	vector<int> path(n + 1, INF);

	for (int i = 1; i <= m; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		adj[s].push_back(make_pair(e, w));
		adj[e].push_back(make_pair(s, w));
	}
	
	djikstra(n, adj, dist, path);

	return 0;
}