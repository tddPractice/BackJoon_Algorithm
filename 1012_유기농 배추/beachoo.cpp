/*

2018 Feb 13, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int x[4] = { -1, 0, 0, 1 };
int y[4] = { 0, -1, 1, 0 };

void dfs(vector<vector<int> > v, vector<vector<int> > *visited, int i, int j) {
	(*visited)[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		if (v[i + x[k]][j + y[k]] == 1 && (*visited)[i + x[k]][j + y[k]] == 0) {
			dfs(v, visited, i + x[k], j + y[k]);
		}
	}
}

void dfsAll(vector<vector<int> > v, int m, int n) {
	vector<vector<int> > visited(n+2, vector<int>(m+2, 0));
	int cnt = 0;

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m + 1; j++) {
			if (v[i][j] == 1 && visited[i][j] == 0) {
				cnt++;
				dfs(v, &visited, i, j);
			}
		}
	}
	printf("%d\n", cnt);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		vector<vector<int> > v(n + 2, vector<int>(m + 2, 0));

		int a, b;
		for (int i = 1; i <= k; i++) {
			scanf("%d %d", &a, &b);
			v[b + 1][a + 1] = 1;
		}

		dfsAll(v, m, n);
	}

	return 0;
}
