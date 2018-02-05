/*

2018 Feb 02, made by Moon

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int maze[102][102];
int visited[102][102];
int isStacked[102][102];
int posX[4] = { 1, 0, 0, -1 };
int posY[4] = { 0, -1, 1, 0 };

void findPath() {
	queue< pair<int, int> > q;
	q.push(pair<int, int>(1, 1));
	visited[1][1] = 1;
	isStacked[1][1] = 1;

	while (!q.empty()) {
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();


		vector< pair<int, int> > neighbor;
		for (int k = 0; k < 4; k++) {
			int ix, iy;
			ix = x + posX[k], iy = y + posY[k];
			if (maze[ix][iy] != 0 && isStacked[ix][iy] == 0) {
				neighbor.push_back(pair<int, int>(ix, iy));
				visited[ix][iy] = visited[x][y] + 1;
			}
		}

		for (int i = 0; i < neighbor.size(); i++) {
			int first = neighbor[i].first;
			int second = neighbor[i].second;
			q.push(pair<int, int>(first, second));
			isStacked[first][second] = 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			maze[i][j] = 0;
			visited[i][j] = 9999;
			isStacked[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		char t[102];
		cin.getline(t, 100);
		for (int j = 1; j <= m; j++) {
			maze[i][j] = (t[j-1] - '0') == 1 ? 1 : 0;
		}
	}



	visited[1][1] = 1;
	findPath();
	

	// 출력
	printf("%d\n", visited[n][m]);
	return 0;
}
