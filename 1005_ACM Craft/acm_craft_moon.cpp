/*

2018 Mar 27, made by Moon

*/
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void topological_sort() {
	int n, m, k, s, e, r;
	scanf("%d %d", &n, &m);

	queue<int> q;
	vector<int> totalTime(n + 1, 0);
	vector<int> needTime(n + 1, 0);
	vector<int> inDegree(n + 1, 0);
	vector<vector<int> > adj(n + 1, vector<int>());

	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		needTime[i] = k;
		totalTime[i] = k;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		inDegree[e]++;
	}
	scanf("%d", &r);

	while (q.size() != n) {
		for (int i = 1; i <= n; i++) {
			if (inDegree[i] == 0) {
				q.push(totalTime[i]);
				inDegree[i] = -1;

				for (int j = 0; j < adj[i].size(); j++) {
					totalTime[adj[i][j]] = max(totalTime[adj[i][j]], totalTime[i] + needTime[adj[i][j]]);
					inDegree[adj[i][j]]--;
				}
			}
		}
	}

	printf("%d\n", totalTime[r]);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		topological_sort();
	}
	return 0;
}