/*

2018 Mar 24, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int v[101] = { 0 };
int addList[101] = { 0 };
vector<int> top, bot;

void dfs(int r, int visited[101]) {
	visited[r] = 1;
	top.push_back(r);
	bot.push_back(v[r]);

	if (!visited[v[r]]) {
		dfs(v[r], visited);
	}
}

void dfsAll(int n) {
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		int visited[101] = { 0 };
		dfs(i, visited);

		int isSame = 1;
		sort(top.begin(), top.end());
		sort(bot.begin(), bot.end());
		for (int j = 0; j < top.size(); j++) {
			if (top[j] != bot[j]) {
				isSame = 0;
				break;
			}
		}

		if (isSame) {
			for (int j = 0; j < top.size(); j++) {
				if (!addList[top[j]]) {
					res.push_back(top[j]);
					addList[top[j]] = 1;
				}
			}
		}
		top.erase(top.begin(), top.end());
		bot.erase(bot.begin(), bot.end());
	}

	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d\n", res[i]);
	}
}

int main() {
	int n, k;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &k);
		v[i] = k;
	}

	dfsAll(n);
	return 0;
}