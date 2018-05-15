/*

2018 May 15, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 52
using namespace std;

int r, c;
int sx, sy, ex, ey;
int x[4] = { 0, 0, 1,-1 };
int y[4] = { 1,-1,0,0 };
int visited[MAX][MAX];
int isDone = 0;
int ans = 0;
char v[MAX][MAX];
queue<pair<int, int> > q;
queue<pair<int, pair<int, int> > > p;
 
void water() {
	int size = q.size();
	for (int i = 0; i < size; i++) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			if (v[curX + x[k]][curY + y[k]] == '.' || v[curX + x[k]][curY + y[k]] == 'S') {
				v[curX + x[k]][curY + y[k]] = '*';

				if (visited[curX + x[k]][curY + y[k]] == 0) {
					visited[curX + x[k]][curY + y[k]] = 1;
					q.push(make_pair(curX + x[k], curY + y[k]));
				}
			}
		}
	}
}

void escape() {
	int found = 0;
	int size = p.size();

	for (int i = 0; i < size; i++) {
		int curX = p.front().first;
		int curY = p.front().second.first;
		int w = p.front().second.second;
		p.pop();

		if (curX == ex && curY == ey) {
			isDone = 1;
			ans = w;
			return;
		}

		for (int k = 0; k < 4; k++) {
			if (v[curX + x[k]][curY + y[k]] == '.' || v[curX + x[k]][curY + y[k]] == 'D') {
				if (visited[curX + x[k]][curY + y[k]] == 0) {
					visited[curX + x[k]][curY + y[k]] = 1;
					found = 1;
					p.push(make_pair(curX + x[k], make_pair(curY + y[k], w + 1)));
				}
			}
		}
	}

	if (!found) {
		isDone = 1;
	}
}

int main() {
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (j == 1) {
				scanf(" %c", &v[i][j]);
			}
			else {
				scanf("%c", &v[i][j]);
			}

			if (v[i][j] == '*') {
				q.push(make_pair(i, j));
			}

			if (v[i][j] == 'D') {
				ex = i;
				ey = j;
			}
			if (v[i][j] == 'S') {
				sx = i;
				sy = j;
				p.push(make_pair(sx, make_pair(sy, 0)));
			}
		}
	}

	while (true) {
		water();
		escape();

		if (isDone) {
			break;
		}
	}

	if (ans) {
		printf("%d\n", ans);
	}
	else {
		printf("%s\n", "KAKTUS");
	}

	return 0;
}