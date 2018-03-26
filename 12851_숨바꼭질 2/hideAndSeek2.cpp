/*

2018 Mar 26, made by Moon

*/
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

void bfs(int n, int k) {
	int lvCnt, isReturn, ansN;
	queue<int> q;
	map<int, int> visited;
	q.push(n);
	lvCnt = -1;
	isReturn = 0;
	ansN = 0;

	while (!q.empty()) {
		int size = q.size();
		lvCnt++;

		for (int j = 0; j < size; j++) {
			int i = q.front();
			visited[i] = 1;
			q.pop();
			if (i == k) {
				isReturn = 1;
				ansN++;
			}
			if (i + 1 <= k && visited[i + 1] == 0) {
				q.push(i + 1);
			}
			if (i - 1 >= 0 && visited[i - 1] == 0) {
				q.push(i - 1);
			}
			if (i * 2 <= 2 * k && visited[i * 2] == 0) {
				q.push(i * 2);
			}
		}

		if (isReturn) {
			break;
		}
	}

	printf("%d\n%d\n", lvCnt, ansN);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	bfs(n, k);
	return 0;
}