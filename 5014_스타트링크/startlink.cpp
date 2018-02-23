/*

2018 Feb 23, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;

void bfs() {
	vector<int> visited(f + 1, 0);
	queue<int> q;
	q.push(s);

	int cnt = 0;
	int size = q.size();
	while (!q.empty()) {
		int k = q.front();
		visited[k] = 1;
		q.pop();
		size--;

		if (k == g) {
			printf("%d\n", cnt);
			return;
		}
		else {
			if (k + u <= f && k + u >= 1 && !visited[k + u]) {
				q.push(k + u);
				visited[k + u] = 1;
			}
			if (k - d <= f && k - d >= 1 && !visited[k - d]) {
				q.push(k - d);
				visited[k - d] = 1;
			}

			if (size == 0) {
				size = q.size();
				cnt++;
			}
		}
	}
	printf("use the stairs\n");
}

int main() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	bfs();
	return 0;
}