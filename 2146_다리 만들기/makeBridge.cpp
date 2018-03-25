/*

2018 Mar 25, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, v[102][102] = { 0 }, visited[102][102] = { 0 };
int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };
vector<vector<pair<int, int> > > vec(10001, vector<pair<int, int> >());

void dfs(int i, int j, int visited[][102], int cnt) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		if (i + x[k] >= 1 && i + x[k] <= n && j + y[k] >= 1 && j + y[k] <= n &&
			v[i + x[k]][j + y[k]] == 0) {
			vec[cnt].push_back(pair<int, int>(i, j));
			break;
		}
	}

	for (int k = 0; k < 4; k++) {
		if (!visited[i + x[k]][j + y[k]] && v[i + x[k]][j + y[k]]) {
			dfs(i + x[k], j + y[k], visited, cnt);
		}
	}
}

void dfsAll() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && v[i][j]) {
				dfs(i, j, visited, cnt);
				cnt++;
			}
		}
	}

	int minV = 987654321;
	for (int i = 0; i < cnt - 1; i++) {
		for (int l = 0; l < vec[i].size(); l++) {
			for (int j = i + 1; j < cnt; j++) {
				for (int k = 0; k < vec[j].size(); k++) {
					minV = min(minV, abs(vec[j][k].first - vec[i][l].first) +
						abs(vec[j][k].second - vec[i][l].second) - 1);
				}
			}
		}
	}

	if (minV == 987654321) {
		printf("0\n");
	}
	else {
		printf("%d\n", minV);
	}
}

int main() {
	int k;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		vector<pair<int, int> > tmp;
		vec.push_back(tmp);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &k);
			v[i][j] = k;
		}
	}

	dfsAll();
	return 0;
}