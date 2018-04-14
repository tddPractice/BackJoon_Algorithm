/*

2018 Apr 14, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };

void makeFire(int w, int h, queue<pair<int, int> > &fire, vector<vector<int> > &adj) {
	queue<pair<int, int> > f;
	while (!fire.empty()) {
		int size = fire.size();

		for (int i = 0; i < size; i++) {
			int posX = fire.front().first;
			int posY = fire.front().second;
			fire.pop();

			for (int k = 0; k < 4; k++) {
				if (adj[posX + x[k]][posY + y[k]] == 0 || adj[posX + x[k]][posY + y[k]] == 1) {
					f.push(make_pair(posX + x[k], posY + y[k]));
				}
			}
		}
	}

	while (!f.empty()) {
		int posX = f.front().first;
		int posY = f.front().second;
		f.pop();
		fire.push(make_pair(posX, posY));

		adj[posX][posY] = 2;
	}

	queue<pair<int, int> >().swap(f);
}

void bfs(int w, int h, int s, int e, queue<pair<int, int> > fire, vector<vector<int> > &adj) {
	int cnt = 0;
	int isReturn = 0;
	queue<pair<int, int> > q;
	vector<vector<int> > visited(h + 2, vector<int>(w + 2, 0));
	q.push(make_pair(s, e));
	visited[s][e] = 1;

	while (!q.empty()) {
		makeFire(w, h, fire, adj);

		int size = q.size();
		//printf("size:%d\n", size);
		cnt++;

		for (int i = 0; i < size; i++) {
			int posX = q.front().first;
			int posY = q.front().second;
			q.pop();


			for (int k = 0; k < 4; k++) {
				if (adj[posX + x[k]][posY + y[k]] == 3) {
					isReturn = 1;
					break;
				}
				else if (adj[posX + x[k]][posY + y[k]] == 0 && visited[posX + x[k]][posY + y[k]] == 0) {
					q.push(make_pair(posX + x[k], posY + y[k]));
					visited[posX + x[k]][posY + y[k]] = 1;
				}
			}

			if (isReturn) {
				break;
			}
		}

		if (isReturn) {
			break;
		}
	}

	if (isReturn) {
		printf("%d\n", cnt);
	}
	else {
		printf("IMPOSSIBLE\n");
	}

	queue<pair<int, int> >().swap(q);
	vector<vector<int> >().swap(visited);
}

void bfsAll() {
	int w, h, s, e;
	char ch;
	scanf("%d %d", &w, &h);
	getchar();

	vector<vector<int> > adj(h + 2, vector<int>(w + 2, 3));
	queue<pair<int, int> > fire;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%c", &ch);

			// #(-1) 벽
			// .(0) 빈 공간
			// @(1) 현재 위치
			// *(2) 불
			// 3 없는 공간(출구)
			if (ch == '#') {
				adj[i][j] = -1;
			}
			else if (ch == '.') {
				adj[i][j] = 0;
			}
			else if (ch == '@') {
				adj[i][j] = 1;
				s = i;
				e = j;
			}
			else if (ch == '*') {
				adj[i][j] = 2;
				fire.push(make_pair(i, j));
			}
		}
		getchar();
	}

	bfs(w, h, s, e, fire, adj);
	vector<vector<int> >().swap(adj);
	queue<pair<int, int> >().swap(fire);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		bfsAll();
	}
	return 0;
}