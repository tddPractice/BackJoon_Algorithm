/*

2018 May 8, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 501
using namespace std;

int n, m;
vector<vector<int> > v(MAX, vector<int>(MAX, 0));
vector<int> aMatch(MAX, -1), bMatch(MAX, -1);
vector<int> visited(MAX, 0);

bool flow(int r) {
	if (visited[r]) {
		return false;
	}
	visited[r] = 1;

	for (int i = 1; i <= n; i++) {
		if (v[r][i] == 1){
			if (bMatch[i] == -1 || flow(bMatch[i])) {
				bMatch[i] = r;
				aMatch[r] = i;
				return true;
			}
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int r, c;
		scanf("%d %d", &r, &c);

		v[r][c] = 1;
	}

	int match = 0;
	for (int i = 1; i <= n; i++) {
		if (aMatch[i] == -1) {
			for (int j = 1; j <= n; j++) {
				visited[j] = 0;
			}

			if (flow(i)) {
				match++;
			}
		}
	}

	printf("%d\n", match);
	return 0;
}