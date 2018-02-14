/*

2018 Feb 14, made by Moon

*/
#include <cstdio>
#include <iostream>
using namespace std;

int n, h = 0, cnt, maxV = -1;
int v[102][102] = { 0 };
int visited[102][102] = { 0 };
int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0, 0 };

void dfsAll(int);
void dfs(int, int, int);
void initVisited();

int main() {
	scanf("%d", &n);
	int k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
			h = h < v[i][j] ? v[i][j] : h;
		}
	}

	for (int i = 0; i <= h; i++) {
		cnt = 0;
		initVisited();
		dfsAll(i);
		maxV = maxV < cnt ? cnt : maxV;
	}
	printf("%d\n", maxV);
	return 0;
}

void initVisited() {
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			if (i == 0 || i == n+1 || j == 0 || j == n+1) {
				visited[i][j] = -1;
			}
			else {
				visited[i][j] = 0;
			}
		}
	}
}

void dfsAll(int high) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0 && v[i][j] >= high) {
				cnt++;
				dfs(i, j, high);
			}
		}
	}
}

void dfs(int a, int b, int high) {
	visited[a][b] = 1;
	for (int k = 0; k < 4; k++) {
		if (visited[a + x[k]][b + y[k]] == 0 && v[a + x[k]][b + y[k]] >= high) {
			dfs(a + x[k], b + y[k], high);
		}
	}
}
