/*

2018 Apr 4, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

void djikstra(int n, int r, vector<vector<pair<int, int> > > &adj, vector<int> &dist) {
	priority_queue<pair<int, int> > q;
	dist[r] = 0;
	q.push(make_pair(dist[r], r));

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int w = -q.top().first;
			int s = q.top().second;
			q.pop();

			int adjSize = adj[s].size();
			
			for (int j = 0; j < adjSize; j++) {
				if (dist[adj[s][j].first] > dist[s] + adj[s][j].second) {
					dist[adj[s][j].first] = dist[s] + adj[s][j].second;
					q.push(make_pair(-dist[adj[s][j].first], adj[s][j].first));
				}
			}
		}
	}

	int maxV = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;

			maxV = maxV < dist[i] ? dist[i] : maxV;
		}
	}

	printf("%d %d\n", cnt, maxV);
}

void start() {
	int n, d, c;
	scanf("%d %d %d", &n, &d, &c);

	vector<vector<pair<int, int> > > adj(n + 1, vector<pair<int, int> >());
	vector<int> dist(n + 1, INF);

	for (int i = 1; i <= d; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		adj[e].push_back(make_pair(s, w));
	}

	djikstra(n, c, adj, dist);

	vector<vector<pair<int, int> > >().swap(adj);
	vector<int>().swap(dist);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		start();
	}
	return 0;
}