/*

2018 Mar 29, made by Moon

*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

void topological_sort(int n, vector<int> inDegree, vector<vector<int> > adj) {
	queue<int> q;
	int cnt = 0, isReturn = 0;

	while (q.size() != n) {
		for (int i = 1; i <= n; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				inDegree[i] = -1;

				int size = adj[i].size();
				for (int j = 0; j < size; j++) {
					inDegree[adj[i][j]]--;
				}
			}
		}
		cnt++;

		if (cnt > 1000000) {
			printf("0\n");
			isReturn = 1;
			break;
		}
	}

	if (isReturn) {
		return;
	}
	while (!q.empty()) {
		printf("%d\n", q.front());
		q.pop();
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> inDegree(n + 1, 0);
	vector<vector<int> > adj(n + 1, vector<int>());

	while (m--) {
		int k, v;
		vector<int> tmp;
		scanf("%d", &k);

		for (int i = 0; i < k; i++) {
			scanf("%d", &v);
			tmp.push_back(v);
		}
		for (int i = 1; i < tmp.size(); i++) {
			adj[tmp[i - 1]].push_back(tmp[i]);
			inDegree[tmp[i]]++;
		}
		tmp.erase(tmp.begin(), tmp.end());
	}

	topological_sort(n, inDegree, adj);
	return 0;
}