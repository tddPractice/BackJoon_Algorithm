/*

2018 Feb 22, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int v[302][302] = { 0 };
int x[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs(int n, int x1, int y1, int x2, int y2) {
	int visited[302][302] = { 0 };
	vector<vector<int> > v(n + 2, vector<int>());
	queue<pair<int, int> > q;
	q.push(pair<int, int>(x1, y1));

	pair<int, int> p;
	int size = 0, cnt = -1;
	while (!q.empty()) {
		if (size == 0) {
			size = q.size();
			cnt++;
		}
		p = q.front();
		if (p.first == x2 && p.second == y2) {
			printf("%d\n", cnt);
			return;
		}
		q.pop();
		size--;

		for (int i = 0; i < 8; i++) {
			if (p.first + x[i] >= 0 && p.first + x[i] < n && p.second + y[i] >= 0 && p.second + y[i] < n 
				&& !visited[p.first + x[i]][p.second + y[i]]) {
				visited[p.first + x[i]][p.second + y[i]] = 1;
				q.push(pair<int, int>(p.first + x[i], p.second + y[i]));
			}
		}
	}
	printf("%d\n", cnt);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, x1, x2, y1, y2;
		scanf("%d", &n);
		scanf("%d %d", &x1, &y1);
		scanf("%d %d", &x2, &y2);

		bfs(n, x1, y1, x2, y2);
	}
	return 0;
}