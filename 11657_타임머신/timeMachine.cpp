/*

2018 Apr 9, made by Moon

*/
#include <cstdio>
#include <vector>
#define INF 987654321
using namespace std;

void bellmanFord(int n, int r, vector<vector<pair<int, int> > > &adj, vector<int> &dist) {
	int updated = 0;
	int isAllZero = 1;
	dist[r] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				if (dist[adj[j][k].first] > dist[j] + adj[j][k].second) {
					dist[adj[j][k].first] = dist[j] + adj[j][k].second;
					updated = 1;
				}
			}
		}

		if (!updated) {
			break;
		}
		updated = 0;
	}

	//한 번 더 체크
	updated = 0;
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < adj[j].size(); k++) {
			if (dist[adj[j][k].first] > dist[j] + adj[j][k].second) {
				dist[adj[j][k].first] = dist[j] + adj[j][k].second;
				updated = 1;
				break;
			}
		}

		if (updated) {
			break;
		}
	}

	if (updated) {
		printf("-1\n");
	}
	else {

		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) {
				printf("-1\n");
			}
			else {
				printf("%d\n", dist[i]);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<pair<int, int> > > adj(n + 1, vector<pair<int, int> >());
	vector<int> upper(n + 1, INF);

	for (int i = 1; i <= m; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		adj[s].push_back(make_pair(e, w));
	}

	bellmanFord(n, 1, adj, upper);

	return 0;
}