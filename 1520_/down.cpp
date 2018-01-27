#include <iostream>
#include <cstring>
using namespace std;

int inpu[501][501];
int cache[501][501];
int M, N;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int find(int x, int y) {
	
	int& res = cache[x][y];
	if (res != -1) return res;
	if (x == 0 && y == 0) res = 1;
	else {
		res = 0;
		for (int i = 0; i < 4; ++i)
			if (x + dx[i] >= 0 && x + dx[i] < M&&y + dy[i] >= 0 && y + dy[i]<N)
				if (inpu[x + dx[i]][y + dy[i]] > inpu[x][y]) res += find(x + dx[i], y + dy[i]);
	}
	return res;
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> inpu[i][j];

	memset(cache, -1, sizeof(cache));
	cout << find(M - 1, N - 1);
	return 0;
}
