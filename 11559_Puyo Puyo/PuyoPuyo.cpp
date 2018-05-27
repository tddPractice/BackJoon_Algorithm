/*

2018 May 27, made by Moon

*/
#include <cstdio>
#include <queue>

using namespace std;

char v[12][6];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int keepDoing, cnt;

void arrange() {
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (v[i][j] == '.') {
				int k = i - 1;
				while (k >= 0) {
					if (v[k][j] != '.') {
						v[i][j] = v[k][j];
						v[k][j] = '.';
						break;
					}
					k--;
				}
			}
		}
	}
}

void bfs(int r, int c) {
	queue<pair<int, int> > q, li;
	int visited[14][8];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = 0;
		}
	}

	q.push(make_pair(r, c));
	li.push(make_pair(r, c));
	visited[r][c] = 1;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				if (curX + x[k] >= 0 && curX + x[k] <= 11 && curY + y[k] >= 0 && curY + y[k] <= 5) {
					if (visited[curX + x[k]][curY + y[k]] == 0 && v[curX + x[k]][curY + y[k]] == v[r][c]) {
						visited[curX + x[k]][curY + y[k]] = 1;
						q.push(make_pair(curX + x[k], curY + y[k]));
						li.push(make_pair(curX + x[k], curY + y[k]));
					}
				}
			}
		}
	}

	if (li.size() >= 4) {
		keepDoing = 1;
		while (!li.empty()) {
			int curX = li.front().first;
			int curY = li.front().second;
			li.pop();

			v[curX][curY] = '.';
		}
	}
}

void start() {
	cnt = 0;

	do {
		keepDoing = 0;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (v[i][j] != '.') {
					bfs(i, j);
				}
			}
		}
		if (keepDoing) {
			cnt++;
		}

		arrange();
	} while (keepDoing);

	printf("%d\n", cnt);
}

int main() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%c", &v[i][j]);
		}
		getchar();
	}

	start();

	return 0;
}