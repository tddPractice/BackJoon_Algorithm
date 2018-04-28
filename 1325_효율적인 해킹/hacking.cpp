/*

2018 Apr 28, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int n, m, cnt;
vector<vector<int> > adj(MAX, vector<int>());
vector<int> visited(MAX, 0), inDegree(MAX, 0);

void dfs(int r) {
	visited[r] = 1;
	cnt++;

	for (auto i : adj[r]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);

		adj[e].push_back(s);
		inDegree[s]++;
	}

	int minDegree = 99999;
	for (int i = 1; i <= n; i++) {
		minDegree = min(minDegree, inDegree[i]);
	}
	
	vector<pair<int, int> > result;
	vector<int> q;
	for (int i = 1; i <= n; i++) {
		//if (inDegree[i] == minDegree) {
			for (int j = 1; j <= n; j++) {
				visited[j] = 0;
			}

			cnt = 0;
			dfs(i);
			result.push_back(make_pair(cnt, i));
		//}
	}

	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		if (i == 0) {
			q.push_back(result[i].second);
		}
		else {
			if (result[i].first == result[i - 1].first) {
				q.push_back(result[i].second);
			}
			else {
				break;
			}
		}
	}

	sort(q.begin(), q.end());
	for (int i = 0; i < q.size(); i++) {
		printf("%d ", q[i]);
	}
	printf("\n");
	return 0;
}