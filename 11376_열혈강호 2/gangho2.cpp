/*

2018 Apr 27, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 1001
using namespace std;

int n, m;
int employee[MAX], work[MAX], employee2[MAX], visited[MAX];
vector<int> adj[MAX];

bool dfs(int r) {
	if (visited[r]) {
		return false;
	}

	visited[r] = 1;

	for (auto i : adj[r]) {
		if (work[i] == -1 || dfs(work[i])) {
			employee[r] = i;
			work[i] = r;
			return true;
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);

		for (int j = 1; j <= t; j++) {
			int k;
			scanf("%d", &k);
			adj[i].push_back(k);
		}
	}

	fill(employee, employee + MAX, -1);
	fill(work, work + MAX, -1);
	fill(employee2, employee2 + MAX, -1);

	int match = 0;
	for (int i = 1; i <= n; i++) {
		if (employee[i] == -1) {
			fill(visited, visited + MAX, 0);
			if (dfs(i)) {
				match++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (employee2[i] == -1) {
			fill(visited, visited + MAX, 0);
			if (dfs(i)) {
				match++;
			}
		}
	}

	printf("%d\n", match);
	return 0;
}