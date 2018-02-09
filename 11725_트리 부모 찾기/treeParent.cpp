/*

2018 Feb 09, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

void getParent(int, int);

int parent[100001] = { 0 };
vector<vector<int> > v(100001);
vector<int> visit(100001);
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	getParent(1, 1);

	// 결과 출력
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}

void getParent(int root, int p) {
	visit[root] = 1;
	parent[root] = p;
	int size = v[root].size();
	for (int i = 0; i < size; i++) {
		if (!visit[v[root][i]]) {
			getParent(v[root][i], root);
		}
	}
}
