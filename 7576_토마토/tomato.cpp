/*

2018 Feb 02, made by Moon

*/
#include <iostream> 
#include <queue>
using namespace std;

int N;
int M;

int main() {
	cin >> M >> N;

	int val = M * N;
	int tomato[102][102] = { 0 };
	int day = -1;
	queue<pair<int, int>> queue;
	bool boolean;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				tomato[i][j] = -1;
			}
			else {
				cin >> tomato[i][j];
				if (tomato[i][j] == 1) {
					queue.push(pair<int, int>(i, j));
					val--;
				}else if(tomato[i][j] == -1) {
					val--;
				}
			}
		}
	}
	while (!queue.empty()) {
		int size = queue.size();
		day++;

		for (int i = 0; i < size; i++) {
			int r = queue.front().first;
			int c = queue.front().second;
			if (tomato[r - 1][c] == 0) {
				tomato[r - 1][c] = 1;
				val--;
				queue.push(pair<int, int>(r - 1, c));
			}
			if (tomato[r + 1][c] == 0) {
				tomato[r + 1][c] = 1;
				val--;
				queue.push(pair<int, int>(r + 1, c));
			}
			if (tomato[r][c - 1] == 0) {
				tomato[r][c - 1] = 1;
				val--;
				queue.push(pair<int, int>(r, c - 1));
			}
			if (tomato[r][c + 1] == 0) {
				tomato[r][c + 1] = 1;
				val--;
				queue.push(pair<int, int>(r, c + 1));
			}
			queue.pop();
		}

	}

	if (val == 0) {
		cout << day << endl;
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}
