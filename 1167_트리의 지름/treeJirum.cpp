/*

2018 Feb 09, made by Moon

*/
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int n, res = 0;

vector<vector<pair<int, int> > > v(100001);
vector<int> maxV(100001, 0);
vector<int> visited(100001, 0);

void dfs(int, int, int);
int findBiggest();

int main() {
	scanf("%d", &n);
	int vertex, child, weight;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &vertex);
		do {
			scanf("%d", &child);
			if (child == -1) break;
			else {
				scanf("%d", &weight);
				v[vertex].push_back(pair<int, int>(child, weight));
			}
		} while (1);
	}

	int res = 0, maxIdx;

	dfs(1, 0, 0);
	maxIdx = findBiggest();

	for (int i = 1; i <= n; i++) {
		maxV[i] = 0;
		visited[i] = 0;
	}

	dfs(maxIdx, 0, 0);
	maxIdx = findBiggest();
	res += maxV[maxIdx];

	printf("%d\n", res);
	

	return 0;
}

void dfs(int root, int curW, int accW) {
	int size = v[root].size();
	int totalW = curW + accW;
	visited[root] = 1;
	for (int i = 0; i < size; i++) {
		if (!visited[v[root][i].first]) {
			dfs(v[root][i].first, v[root][i].second, totalW);
		}
	}

	maxV[root] = totalW;
}

int findBiggest() {
	int maxIdx = -1, maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (maxV[i] > maxVal) {
			maxVal = maxV[i];
			maxIdx = i;
		}
	}
	return maxIdx;
}
