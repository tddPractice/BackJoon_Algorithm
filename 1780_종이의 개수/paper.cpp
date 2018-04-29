/*

2018 Apr 30, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 2200
using namespace std;

int n;
int a, b, c;

void solve(int x, int y, int w, vector<vector<int> > &v) {
	int num = -2;
	int isSame = 1;
	
	for (int i = x; i < x + w; i++) {
		for (int j = y; j < y + w; j++) {
			if (i == x && j == y) {
				num = v[i][j];
			}
			else {
				if (num != v[i][j]) {
					isSame = 0;
					break;
				}
			}
		}

		if (!isSame) {
			break;
		}
	}
	
	if (!isSame) {
		solve(x, y, w / 3  , v);
		solve(x, y + (w / 3), w / 3  , v);
		solve(x, y + (w * 2 / 3), w / 3  , v);
		
		solve(x + (w / 3), y, w / 3, v);
		solve(x + (w / 3), y + (w / 3), w / 3, v);
		solve(x + (w / 3), y + (w * 2/ 3), w / 3, v);
		
		solve(x + (w * 2 / 3), y, w / 3, v);
		solve(x + (w * 2 / 3), y + (w / 3), w / 3, v);
		solve(x + (w * 2 / 3), y + (w * 2 / 3), w / 3, v);
	}
	else {
		if (num == -1) {
			a++;
		}
		else if (num == 0) {
			b++;
		}
		else if (num == 1) {
			c++;
		}
	}
}

int main() {
	scanf("%d", &n);
	vector<vector<int> > v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	a = 0;
	b = 0;
	c = 0;
	solve(0, 0, n, v);

	printf("%d\n%d\n%d\n", a, b, c);

	return 0;
}