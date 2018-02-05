/*

2018 Feb 05, made by Moon

*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void getCandy(int n, int m, int map[][1002], int result[][1002]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			result[i][j] = map[i][j] + max(result[i-1][j-1], max(result[i-1][j], result[i][j-1]));
		}
	}
	printf("%d\n", result[n][m]);
}

int main() {
	int n, m;
	int map[1002][1002] = { 0, };
	int result[1002][1002] = { 0, };

	scanf("%d %d", &n, &m);
	getchar();

	int c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			map[i][j] = c;
		}
	}

	getCandy(n, m, map, result);

	return 0;
}
