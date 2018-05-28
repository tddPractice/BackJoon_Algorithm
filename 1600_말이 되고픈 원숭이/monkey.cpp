/*

2018 May 28, made by Moon

*/
#include <cstdio>
#include <queue>

#define MAX 206
#define MAXK 30
using namespace std;

int t, n, m;
int v[MAX][MAX], visited[MAXK][MAX][MAX];
int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };
int j[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int l[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int ans;

void bfs() {
	int cnt = 0;
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(3, make_pair(3, t)));
	visited[t][3][3] = 1;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int curX = q.front().first;
			int curY = q.front().second.first;
			int tr = q.front().second.second;
			q.pop();

			if (curX == n && curY == m) {
				ans = cnt;
				queue<pair<int, pair<int, int> > >().swap(q);
				return;
			}

			for (int k = 0; k < 4; k++) {
				if (v[curX + x[k]][curY + y[k]] == 0 && visited[tr][curX + x[k]][curY + y[k]] == 0) {
					visited[tr][curX + x[k]][curY + y[k]] = 1;
					q.push(make_pair(curX + x[k], make_pair(curY + y[k], tr)));
				}
			}

			for (int k = 0; k < 8; k++) {
				if (tr != 0 && v[curX + j[k]][curY + l[k]] == 0 && visited[tr - 1][curX + j[k]][curY + l[k]] == 0) {
					visited[tr - 1][curX + j[k]][curY + l[k]] = 1;
					q.push(make_pair(curX + j[k], make_pair(curY + l[k], tr - 1)));
				}
			}
		}
		cnt++;
	}
}

int main() {
	scanf("%d %d %d", &t, &m, &n);

	for (int i = 0; i < MAX; i++) {
		for (int u = 0; u < MAX; u++) {
			v[i][u] = -1;
		}
	}

	n += 2;
	m += 2;

	for (int l = 0; l < MAXK; l++) {
		for (int i = 0; i < MAX; i++) {
			for (int u = 0; u < MAX; u++) {
				visited[l][i][u] = 0;
			}
		}
	}

	for (int i = 3; i <= n; i++) {
		for (int u = 3; u <= m; u++) {
			scanf("%d", &v[i][u]);
		}
	}

	ans = -1;
	bfs();
	printf("%d\n", ans);

	return 0;
}