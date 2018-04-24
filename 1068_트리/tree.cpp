/*

2018 Apr 24, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k, r, root;
	scanf("%d", &n);

	vector<int> parent(n + 1, -1);
	vector<vector<int> > child(n + 1, vector<int>());

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);

		if (k == -1) {
			parent[i] = k;
			root = i;
		}
		else {
			parent[i] = k;
			child[k].push_back(i);
		}
	}

	scanf("%d", &r);

	if (r == root) {
		printf("0\n");
		return 0;
	}

	int par = parent[r];
	for (int i = 0; i < child[par].size(); i++) {
		if (child[par][i] == r) {
			child[par].erase(child[par].begin() + i);
		}
	}

	//count
	queue<int> q;
	q.push(root);

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < child[cur].size(); j++) {
				if (child[child[cur][j]].size() == 0) {
					cnt++;
				}
				else {
					q.push(child[cur][j]);
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}