/*

2018 Feb 23, made by Moon

*/
#include <cstdio>
#include <queue>
using namespace std;

int v[101][101] = { 0 };
int minV = 98765432;
int minIdx = 101;

void bfs(int r, int n) {
	int cnt = 0;
	int visited[101] = { 0 };
	int path[101] = { 0 };
	queue<int> q;
	q.push(r);

	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
		path[i] = 0;
	}

	int size = 0;
	while (!q.empty()) {
		if (size == 0) {
			cnt++;
			size = q.size();
		}
		int k = q.front();
		visited[k] = 1;
		q.pop();
		size--;

		for (int i = 1; i <= n; i++) {
			if (v[k][i]) {
				if (visited[i]) {
					if (path[i] > cnt) {
						path[i] = cnt;
					}
				}
				else {
					q.push(i);
					visited[i] = 1;
					path[i] = cnt;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += path[i];
	}
	if (minV > sum) {
		minV = sum;
		minIdx = r;
	}
}

void bfsAll(int n) {

	for (int i = 1; i <= n; i++) {
		bfs(i, n);
	}
	printf("%d\n", minIdx);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	//v초기화
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			v[i][j] = 0;
		}
	}

	//입력
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a][b] = 1;
		v[b][a] = 1;
	}

	bfsAll(n);

	return 0;
}