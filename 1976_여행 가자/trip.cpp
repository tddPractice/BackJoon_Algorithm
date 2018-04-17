/*

2018 Apr 18, made by Moon

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
	int n, m, k;
	int p, q;
	scanf("%d %d", &n, &m);

	vector<int> parent(n + 1, 0), height(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &k);

			if (k == 1) {
				p = find(i, parent);
				q = find(k, parent);

				if (p < q) {
					parent[p] = parent[q];
				}
				else {
					parent[q] = parent[p];
				}

				if (p == q) {
					height[p]++;
				}
			}
		}
	}

	int root = 0, sameRoot = 1, isDone = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);

		if (!isDone) {
			if (i == 1) {
				root = find(k, parent);
			}
			else {
				if (root != find(k, parent)) {
					sameRoot = 0;
					isDone = 1;
				}
			}
		}
	}

	if (sameRoot == 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
	return 0;
}