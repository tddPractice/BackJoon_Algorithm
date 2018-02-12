/*

2018 Feb 12, made by Moon

*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int total = 100;
	int h[9], hSum = 0;
	for (int i = 0; i < 9; i++) {
		int k;
		scanf("%d", &k);
		h[i] = k;
	}

	for (int i = 0; i < 9; i++) {
		hSum += h[i];
	}

	int first, second;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				if (hSum - (h[i] + h[j]) == 100) {
					first = i;
					second = j;
					break;
				}
			}
		}
	}

	priority_queue<int> q;
	for (int i = 0; i < 9; i++) {
		if (i != first && i != second) {
			q.push(h[i]);
		}
	}

	int ans[8], i = 6;
	while (!q.empty()) {
		ans[i--] = q.top();
		q.pop();
	}

	for (int i = 0; i < 7; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
