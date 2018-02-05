/*

2018 Feb 04, made by Moon

*/
#include <cstdio>

using namespace std;

int N, M;
int graph[101][101] = { 0, };
int visited[101] = { 0, };
int cnt = 0;

void dfs(int u) {
	visited[u] = 1;

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && graph[u][i] == 1) {
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	scanf("%d", &N);
	getchar();
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	dfs(1);
	printf("%d\n", cnt);

	return 0;
}
