/*

2018 Feb 21, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int cnt = 0;
vector<vector<int> > v;

int bfs(int, int, int);

int main() {
	int t, s, e, m;
	scanf("%d", &t);
	scanf("%d %d", &s, &e);
	scanf("%d", &m);

	for (int i = 0; i <= t; i++) {
		v.push_back(vector<int>());
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	
	printf("%d\n", bfs(t, s, e));

	return 0;
}

int bfs(int n, int start, int end) {
	int size;
	queue<int> q;
	vector<int> visited(n + 1, 0);
	q.push(start);
	visited[start] = 1;
	size = q.size();

	while (!q.empty()) {
		int r = q.front();
		q.pop();

		if (r == end) {
			return cnt;
		}

		for (int i = 0; i < v[r].size(); i++) {
			if (!visited[v[r][i]]) {
				visited[v[r][i]] = 1;
				q.push(v[r][i]);
			}
		}
		size--;
		if (size == 0) {
			cnt++;
			size = q.size();
		}
	}
	return -1;
}
