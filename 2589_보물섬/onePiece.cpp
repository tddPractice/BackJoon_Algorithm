/*

2018 Mar 18, made by Moon

*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0, 0 };
int visited[52][52] = { 0 };
char v[52][52];

int dfsLongest(int i, int j) {
	int time = -1;
	pair<int, int> p;
	queue<pair<int, int> > q;
	q.push(pair<int, int>(i, j));

	while (!q.empty()) {
		int size = q.size();
		
		if (size == 0) {
			break;
		}

		for (int a = 0; a < size; a++) {
			p = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				if (v[p.first + x[k]][p.second + y[k]] == 'L' &&
					visited[p.first + x[k]][p.second + y[k]] == 0) {
					q.push(pair<int, int>(p.first + x[k], p.second + y[k]));
					visited[p.first + x[k]][p.second + y[k]] = 1;
				}
			}
		}
		time++;
	}
	return time;
}

int findLongest(int i, int j) {
	int time = 0, isDone = 0, posX, posY;
	pair<int, int> p;
	queue<pair<int, int> > q;
	q.push(pair<int, int>(i, j));
	visited[i][j] = 1;

	while (!q.empty()) {
		int size = q.size();

		for (int a = 0; a < size; a++) {
			p = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				if (v[p.first + x[k]][p.second + y[k]] == 'L' &&
					visited[p.first + x[k]][p.second + y[k]] == 0) {
					q.push(pair<int, int>(p.first + x[k], p.second + y[k]));
					visited[p.first + x[k]][p.second + y[k]] = 1;
				}
			}
		}
	}

	for (int a = 1; a <= 51; a++) {
		for (int b = 1; b <= 51; b++) {
			visited[a][b] = 0;
		}
	}

	time = dfsLongest(p.first, p.second);
	return time;
}

int main() {
	int n, m;
	char ch;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			v[i][j] = ch;
		}
	}

	int time = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == 'L') {
				time = max(time, findLongest(i, j));

				for (int a = 1; a <= 51; a++) {
					for (int b = 1; b <= 51; b++) {
						visited[a][b] = 0;
					}
				}
			}
		}
	}
	printf("%d\n", time);
	return 0;
}