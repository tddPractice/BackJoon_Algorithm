/*

2018 Feb 20, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > v;
vector<int> visited;

void bfs(int);

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		visited.push_back(0);
		v.push_back(vector<int>());
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			bfs(i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}

void bfs(int u) {
	queue<int> q;
	q.push(u);

	while (!q.empty()) {
		int r = q.front();
		q.pop();
		visited[r] = 1;

		for (int i = 0; i < v[r].size(); i++) {
			if (!visited[v[r][i]]) {
				int k = v[r][i];
				visited[k] = 1;
				q.push(v[r][i]);
			}
		}
	}
}
