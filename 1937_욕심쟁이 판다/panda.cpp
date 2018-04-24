/*

2018 Apr 23, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d", &n);

	int x[4] = { 0, 0, 1, -1 };
	int y[4] = { 1, -1, 0, 0 };
	vector<vector<int> > v(n + 2, vector<int>(n + 2, 0));
	vector<vector<int> > adj(n + 2, vector<int>(n + 2, -1));
	vector<pair<int, pair<int, int> > > q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adj[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &k);
			v[i][j] = k;
			q.push_back(make_pair(k, make_pair(i, j)));
		}
	}
	
	sort(q.begin(), q.end());

	long long maxV = 1;
	int size = q.size();
	for (int p = 0; p < size; p++) {
		int i = q[p].second.first;
		int j = q[p].second.second;

		for (int k = 0; k < 4; k++) {
			if (v[i][j] < v[i + x[k]][j + y[k]]) {
				if (adj[i][j] + 1 > adj[i + x[k]][j + y[k]]) {
					adj[i + x[k]][j + y[k]] = adj[i][j] + 1;
					maxV = adj[i + x[k]][j + y[k]] > maxV ? adj[i + x[k]][j + y[k]] : maxV;
				}
			}
		}
	}
	printf("%lld\n", maxV);
	return 0;
}