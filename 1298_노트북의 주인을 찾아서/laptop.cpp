/* 

2018 Apr 27, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 101
#define MMAX 5001
using namespace std;

int n, m;
int person[MMAX], laptop[MMAX], visited[MMAX];
vector<int> adj[MMAX];

bool dfs(int r) {
	if (visited[r]) {
		return false;
	}

	visited[r] = 1;

	for (auto i : adj[r]) {
		if (laptop[i] == -1 || dfs(laptop[i])) {
			person[r] = i;
			laptop[i] = r;
			return true;
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
	}

	fill(person, person + MMAX, -1);
	fill(laptop, laptop + MMAX, -1);

	int match = 0;
	for (int i = 1; i <= n; i++) {
		if (person[i] == -1) {
			fill(visited, visited + MMAX, 0);
			if (dfs(i)) {
				match++;
			}
		}
	}

	printf("%d\n", match);

	return 0;
}