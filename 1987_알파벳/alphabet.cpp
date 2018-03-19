/*

2018 Mar 18, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };
char v[22][22];
int dfs(int i, int j, vector<int> alpha, int cnt) {
	int count = cnt;
	alpha[v[i][j] - 65] = 1;
	for (int k = 0; k < 4; k++) {
		if (((v[i + x[k]][j + y[k]] & 0b01000000) == 0b01000000) &&
			alpha[v[i + x[k]][j + y[k]] - 65] == 0) {
			count = max(count, dfs(i + x[k], j + y[k], alpha, cnt + 1));
		}
	}
	return count;
}

int main() {
	int n, m;
	vector<int> alpha;
	char ch;
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			v[i][j] = ch;
		}
		getchar();
	}

	for (int i = 0; i < 27; i++) {
		alpha.push_back(0);
	}

	alpha[v[1][1] - 65] = 1;
	int cnt = dfs(1, 1, alpha, 1);
	printf("%d\n", cnt);
	return 0;
}