/*

2018 Apr 29, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 200001
using namespace std;

int n;
vector<vector<int> > vM(MAX, vector<int>());
vector<vector<int> > v(MAX, vector<int>());

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		if (x < 0) {
			vM[-x].push_back(y);
		}
		else {
			v[x].push_back(y);
		}
	}

	for (int i = MAX - 1; i >= 0; i--) {
		if (vM[i].size() > 0) {
			sort(vM[i].begin(), vM[i].end());

			for (int j = 0; j < vM[i].size(); j++) {
				printf("%d %d\n", -i, vM[i][j]);
			}
		}
	}

	for (int i = 0; i < MAX; i++) {
		if (v[i].size() > 0) {
			sort(v[i].begin(), v[i].end());

			for (int j = 0; j < v[i].size(); j++) {
				printf("%d %d\n", i, v[i][j]);
			}
		}
	}
	return 0;
}