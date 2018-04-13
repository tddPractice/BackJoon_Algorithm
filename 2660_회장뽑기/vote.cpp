/*

2018 Apr 14, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
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

	priority_queue<pair<int, int> > q;
	priority_queue<int> ans;

	int maxV;
	for (int i = 1; i <= n; i++) {
		maxV = -1;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				maxV = max(maxV, adj[i][j]);
			}
		}
		q.push(make_pair(-maxV, i));
	}

	maxV = -q.top().first;
	
	while (!q.empty()) {
		int val = -q.top().first;
		int idx = q.top().second;
		q.pop();

		if (maxV == val) {
			ans.push(-idx);
		}
		else {
			break;
		}
	}

	printf("%d %d\n", maxV, ans.size());

	while (!ans.empty()) {
		printf("%d ", -ans.top());
		ans.pop();
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);

	vector<vector<int> > adj(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; i++) {
		adj[i][i] = 0;
	}

	while (true) {
		int s, e;
		scanf("%d %d", &s, &e);

		if (s == -1 && e == -1) {
			break;
		}

		adj[s][e] = 1;
		adj[e][s] = 1;
	}

	floyd(n, adj);
	return 0;
}