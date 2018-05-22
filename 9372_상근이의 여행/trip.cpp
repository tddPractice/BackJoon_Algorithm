/*

2018 May 22, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 1001
using namespace std;

int n, m;

void bfs(vector<int> v[MAX], vector<int> visited) {
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < v[cur].size(); j++) {
				if (!visited[v[cur][j]]) {
					visited[v[cur][j]] = 1;
					q.push(v[cur][j]);
					cnt++;
				}
			}
		}
	}

	printf("%d\n", cnt);
}

void start() {
	scanf("%d %d", &n, &m);
	vector<int> v[MAX];
	vector<int> visited(MAX, 0);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(v, visited);

}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		start();
	}
	return 0;
}