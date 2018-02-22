/*

2018 Feb 23, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int t, k;
vector<int> path;
void dfs(int r, int cnt, vector<int> numbers) {
	if (path.size() == 6) {
		for (int i = 0; i < path.size(); i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
	}

	for (int i = 1; i <= 49; i++) {
		if (numbers[i] > 0 ) {
			if (!(path.size() && i <= path.back())) {
				numbers[i]--;
				path.push_back(i);
				dfs(i, cnt + 1, numbers);
				numbers[i]++;
			}
		}
	}
	if(path.size())
		path.pop_back();	
}

int main() {
	while (1) {
		scanf("%d", &t);

		if (!t)
			break;

		vector<int> numbers(50, 0);
		for (int i = 0; i < 50; i++) {
			numbers[i] = 0;
		}

		for (int i = 0; i < t; i++) {
			scanf("%d", &k);
			numbers[k]++;
		}

		int cnt = 0;
		int start;
		for (int i = 1; i < 49; i++) {
			if (numbers[i] > 0) {
				start = i;
				break;
			}
		}
		dfs(start, cnt, numbers);
	}
	return 0;
}