/*

2018 Mar 27, made by Moon

*/
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	queue<int> q;

	scanf("%d", &n);

	vector<int> totalTime(n + 1, 0);
	vector<int> needTime(n + 1, 0);
	vector<int> inDegree(n + 1, 0);
	vector<vector<int> > adj(n + 1, vector<int>());

	for (int i = 1; i <= n; i++) {
		int j = 1;
		while (true) {
			scanf("%d", &k);
			if (k == -1) {
				break;
			}

			if (j == 1) {
				needTime[i] = k;
				totalTime[i] = k;
				j++;
			}
			else {
				adj[k].push_back(i);
				inDegree[i]++;
			}
		}
	}

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

	for (int i = 1; i < totalTime.size(); i++) {
		printf("%d\n", totalTime[i]);
	}
	return 0;
}