/*

2018 Feb 13, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int x[8] = { -1, 0, 0, 1, -1, 1, 1, -1 };
int y[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

void dfsAll(int [][53], int, int);
void dfs(int , int , int [][53], int [][53]);

int main() {
	int w, h;
	while (true) {
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) {
			break;
		}
		else {
			int v[53][53] = { 0 };
			int k;
			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= w; j++) {
					scanf("%d", &k);
					v[i][j] = k;
				}
			}
			dfsAll(v, w, h);
		}
	}
	return 0;
}

void dfsAll(int v[][53],int w,int h) {
	int visited[53][53] = { 0 };
	int cnt = 0;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (v[i][j] == 1 && visited[i][j] == 0) {
				cnt++;
				dfs(i, j, visited, v);
			}
		}
	}
	printf("%d\n", cnt);
}

void dfs(int i, int j, int visited[][53], int v[][53]) {
	visited[i][j] = 1;
	for (int k = 0; k < 8; k++) {
		if (v[i + x[k]][j + y[k]] == 1 && visited[i + x[k]][j + y[k]] == 0) {
			dfs(i+x[k], j+y[k], visited, v);
		}
	}
}
