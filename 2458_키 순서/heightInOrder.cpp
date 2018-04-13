/*

2018 Apr 14, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 999999
using namespace std;

void floyd(int n, vector<vector<int> > &topAdj, vector<vector<int> > &bottomAdj) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				topAdj[i][j] = min(topAdj[i][j], topAdj[i][k] + topAdj[k][j]);
				bottomAdj[i][j] = min(bottomAdj[i][j], bottomAdj[i][k] + bottomAdj[k][j]);
			}
		}
	}

	int cnt = 0, isReturn;
	for (int i = 1; i <= n; i++) {
		isReturn = 0;
		for (int j = 1; j <= n; j++) {
			if(topAdj[i][j] == INF && bottomAdj[i][j] == INF){
				isReturn = 1;
				break;
			}
		}

		if(!isReturn){
			cnt++;
		}
	}

	printf("%d\n", cnt);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int> > topAdj(n + 1, vector<int>(n + 1, INF));
	vector<vector<int> > bottomAdj(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; i++) {
		topAdj[i][i] = 1;
		bottomAdj[i][i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);

		topAdj[s][e] = 1;
		bottomAdj[e][s] = 1;
	}

	floyd(n, topAdj, bottomAdj);

	return 0;
}