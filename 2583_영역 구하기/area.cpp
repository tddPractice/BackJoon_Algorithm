/*

2018 Feb 14, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, tot = 0;
int x[4] = { -1, 0, 0, 1 };
int y[4] = { 0, 1, -1, 0 };
int v[102][102] = { 0 };
int visited[102][102] = { 0 };
vector<int> res;

void dfsAll();
void dfs(int, int);

int main() {
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
				v[i][j] = -1;
				visited[i][j] = -1;
			}
			else {
				v[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}

	int x1, y1, x2, y2;
	while (k--) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1+1; i <= x2; i++) {
			for (int j = y1+1; j <= y2; j++) {
				v[i][j] = 1;
			}
		}
	}

	dfsAll();
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}

void dfsAll() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == 0 && v[i][j] == 0) {
				cnt++;
				dfs(i,j);
				res.push_back(tot);
				tot = 0;
			}
		}
	}
	printf("%d\n", cnt);
}

void dfs(int a, int b) {
	visited[a][b] = 1;
	tot++;
	for (int s = 0; s < 4; s++) {
		if (visited[a + x[s]][b + y[s]] == 0 && v[a + x[s]][b + y[s]] == 0) {
			dfs(a + x[s], b + y[s]);
		}
	}
}
