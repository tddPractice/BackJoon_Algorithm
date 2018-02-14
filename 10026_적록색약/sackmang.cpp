/*

2018 Feb 14, made by Moon

*/
#include <cstdio>
using namespace std;

int n;
int x[4] = { 0, 1, -1, 0 };
int y[4] = { 1, 0, 0, -1 };

int v[102][102] = { 0 };
int sackV[102][102] = { 0 };
int visited[102][102] = { 0 };

void dfs(int [][102], int, int);
void dfsAll(int [][102]);

int main() {
	scanf("%d", &n);
	getchar();
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &c);
			if (c == 'R') {
				v[i][j] = 1;
				sackV[i][j] = 1;
			}
			else if (c == 'G') {
				v[i][j] = 2;
				sackV[i][j] = 1;
			}
			else if (c == 'B') {
				v[i][j] = 3;
				sackV[i][j] = 2;
			}
		}
		getchar();
	}

	dfsAll(v);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = 0;
		}
	}
	dfsAll(sackV);
	printf("\n");
	return 0;
}

void dfs(int arr[][102], int a, int b) {
	visited[a][b] = 1;

	for (int k = 0; k < 4; k++) {
		if (!visited[a + x[k]][b + y[k]] && arr[a + x[k]][b + y[k]] == arr[a][b]) {
			dfs(arr, a + x[k], b + y[k]);
		}
	}
}

void dfsAll(int arr[][102]) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				cnt++;
				dfs(arr, i, j);
			}
		}
	}
	printf("%d ", cnt);
}
