/*

2018 Apr 17, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int find(int n, vector<int> &parent) {
	if (parent[n] == n) {
		return n;
	}

	return find(parent[n], parent);
}

int main() {
	int n, m;
	int rootA, rootB;
	scanf("%d %d", &n, &m);

	vector<int> parent(n + 1, 0), rank(n + 1, 0);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		int x, s, e;
		int rootA, rootB;
		scanf("%d %d %d", &x, &s, &e);

		rootA = find(s, parent);
		rootB = find(e, parent);

		if (x == 0) {

				if (rank[rootA] <= rank[rootB]) {
					parent[rootA] = parent[rootB];
				}
				else {
					parent[rootB] = parent[rootA];
				}

				if (rank[rootA] == rank[rootB]) {
					rank[rootA]++;
				}
		}
		else if (x == 1) {
			if (rootA == rootB) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}