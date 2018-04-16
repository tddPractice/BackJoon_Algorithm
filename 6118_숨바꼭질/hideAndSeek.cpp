/*

2018 Apr 16, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

void djikstra(int n, int r, vector<vector<pair<int, int> > > &adj, vector<int> &dist) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, r));
	dist[r] = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int w = -q.top().first;
			int e = q.top().second;
			q.pop();

			for (int j = 0; j < adj[e].size(); j++) {
				if (dist[adj[e][j].first] == INF || dist[adj[e][j].first] > w + dist[e]) {
					dist[adj[e][j].first] = adj[e][j].second + w;
					q.push(make_pair(-dist[adj[e][j].first], adj[e][j].first));
				}
			}
		}
	}

	priority_queue<pair<int, int> > t;
	for (int i = 1; i <= n; i++) {
		t.push(make_pair(-dist[i], i));
	}

	int maxV = -t.top().first;
	int maxIdx = t.top().second;
	int maxCnt = 1;
	t.pop();

	while(!t.empty()) {
		if (maxV > -t.top().first) {
			break;
		}
		else if (maxV == -t.top().first) {
			if (maxIdx > -t.top().second) {
				maxIdx = t.top().second;
				maxCnt++;
			}
		}
		else if (maxV < -t.top().first) {
			maxV = -t.top().first;
			maxIdx = t.top().second;
			maxCnt = 1;
		}
		t.pop();
	}

	printf("%d %d %d\n", maxIdx, maxV, maxCnt);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<pair<int, int> > > adj(n + 1, vector<pair<int, int> >());
	vector<int> dist(n + 1, INF);

	for (int i = 1; i <= m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);

		adj[s].push_back(make_pair(e, 1));
		adj[e].push_back(make_pair(s, 1));
	}

	djikstra(n, 1, adj, dist);

	return 0;
}