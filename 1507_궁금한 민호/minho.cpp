/*

2018 May 5, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 21
#define INF 9999999
using namespace std;

int n;
int v[MAX][MAX];
int c[MAX][MAX];

int floyd() {
	int tot = 0;
	bool pass = true, save = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				for (int k = 0; k < n; k++) {
					if (v[i][k] != 0 && v[k][j] != 0) {
						if (v[i][j] > v[i][k] + v[k][j]) {
							save = false;
							pass = false;
						}
						else if (v[i][j] == v[i][k] + v[k][j]) {
							save = false;
						}
					}
				}

				if(!pass){
					return -1;
				}
				if (save) {
					c[i][j] = 1;
				}
				save = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j]) {
				tot += v[i][j];
			}
		}
	}
	return tot / 2;
}

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (v[i][j] != v[j][i]) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);

			c[i][j] = 0;
		}
	}

	if (check()) {
		printf("%d\n", floyd());
	}
	else {
		printf("-1\n");
	}
	return 0;
}