/*

2018 Feb 05, made by Moon

*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int apt[27][27] = { 0, };
int visited[27][27] = { 0, };
int posX[4] = { -1, 0, 0, 1 };
int posY[4] = { 0, 1, -1, 0 };
int cnt = 0;
vector<int> vec;

void dfs(int x, int y) {
	int ix, ixLen, jx, jxLen, kx;
	visited[x][y] = 1;

	for (kx = 0; kx < 4; kx++) {
		if (apt[x + posX[kx]][y + posY[kx]] == 1 && visited[x + posX[kx]][y + posY[kx]] == 0) {
			cnt++;
			dfs(x + posX[kx], y + posY[kx]);
		}
	}
}

void dfsAll() {
	int ix, ixLen, jx, jxLen;
	for (ix = 1, ixLen = n; ix <= ixLen; ix++) {
		for (jx = 1, jxLen = n; jx <= jxLen; jx++) {
			if (apt[ix][jx] == 1 && visited[ix][jx] == 0) {
				cnt++;
				dfs(ix, jx);
				vec.push_back(cnt);
				cnt = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	getchar();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			apt[i][j] = 0;
			visited[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		char s[26];
		cin.getline(s, 26);
		for (int j = 1; j <= n; j++) {
			apt[i][j] = (s[j - 1] - '0') == 1 ? 1 : 0;
		}
	}

	dfsAll();

	sort(vec.begin(), vec.end());
	printf("%d\n", vec.size());
	for (int i = 0; i < vec.size(); i++) {
		printf("%d\n", vec[i]);
	}
	

	return 0;
}
