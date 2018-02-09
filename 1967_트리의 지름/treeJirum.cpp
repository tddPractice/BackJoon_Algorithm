/*

2018 Feb 09, made by Moon

*/
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > > vec(10001);
vector<bool> visitedF(10001);
vector<bool> visitedS(10001);
vector<int> first(10001);
vector<int> second(10001);
int n, res = 0;

void dfsF(int, int, int);
void dfsS(int, int, int);
int findBiggestNode(vector<int>);

int main() {
	scanf("%d", &n);

	int u, v, w;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &w);

		vec[u].push_back(pair<int, int>(v, w));
		vec[v].push_back(pair<int, int>(u, w));
	}


	int maxNode;
	dfsF(1, 0, 0);
	maxNode = findBiggestNode(first);
	dfsS(maxNode, 0, 0);
	res = 0;
	maxNode = findBiggestNode(second);
	printf("%d\n", res);
	return 0;
}

void dfsF(int u, int w, int totalW) {
	visitedF[u] = true;
	int weight = w + totalW;
	for (int j = 0; j < vec[u].size(); j++) {
		if (!visitedF[vec[u][j].first]) {
			dfsF(vec[u][j].first, vec[u][j].second, weight);
		}
	}
	first[u] = weight;
}

void dfsS(int u, int w, int totalW) {
	visitedS[u] = true;
	int weight = w + totalW;
	for (int j = 0; j < vec[u].size(); j++) {
		if (!visitedS[vec[u][j].first]) {
			dfsS(vec[u][j].first, vec[u][j].second, weight);
		}
	}
	second[u] = weight;
}

int findBiggestNode(vector<int> v) {
	int maxIdx, maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (maxVal < v[i]) {
			maxIdx = i;
			maxVal = v[i];
		}
	}
	res += maxVal;
	return maxIdx;
}
