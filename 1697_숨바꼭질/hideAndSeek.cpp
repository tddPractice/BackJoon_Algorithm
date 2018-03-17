/*

2018 Mar 17, made by Moon

*/
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int isReturn = 0;
void bfs(int n, int k) {
	int time = 0;
	int plus[200002] = { 0 }, minus[200002] = { 0 }, multi[200002] = { 0 };
	map<int, int> m;
	queue<int> q;
	q.push(n);
	m[n] = 1;

	for (int i = 0; i < 200002; i++) {
		plus[i] = -1;
		minus[i] = -1;
		multi[i] = -1;
	}

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int node = q.front();
			q.pop();
			if (node == k) {
				isReturn = 1;
				break;
			}
			else {
				if (node - 1 >= 0) {
					if (minus[node] == -1 && !m[node - 1]) {
						minus[node] = 1;
						m[node - 1] = 1;
						q.push(node - 1);
					}
				}
				if (node + 1 <= k) {
					if (plus[node] == -1 && !m[node + 1]) {
						plus[node] = 1;
						m[node + 1] = 1;
						q.push(node + 1);
					}
				}
				if (node <= k && node * 2 > 0) {
					if (multi[node] == -1 && !m[node * 2]) {
						multi[node] = 1;
						m[node * 2] = 1;
						q.push(node * 2);
					}
				}
			}
		}
		if (isReturn) {
			printf("%d\n", time);
			break;
		}
		else {
			time++;
		}
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	bfs(n, k);
	return 0;
}