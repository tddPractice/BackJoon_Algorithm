/*

2018 Feb 11, made by Moon

*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int> > tree(10001, pair<int, int>(-1, -1));
vector<vector<int> > v(10001, vector<int>());
vector<int> visited(10001, 0);
int n, order = 1;

int searchRoot();
void insertNode(int, int, int);
void dfs(int, int);

int main(){
	scanf("%d", &n);

	for(int i = 1; i<= n; i++) {
		int root, left, right;
		scanf("%d %d %d", &root, &left, &right);

		insertNode(root, left, right);
	}

	int root = searchRoot();
	dfs(root, 1);

	long long maxIdx = 98765432, maxVal = -1;
	maxVal = 0;
	maxIdx = 1;
	for (int i = 1; i <= n; i++) {
		if (v[i].size()) {
			int m = v[i].back() - v[i].front() > 0 ? v[i].back() - v[i].front() : 0;
			int ix = i;
			if (maxVal == m) {
				maxIdx = maxIdx > i ? i : maxIdx;
			}
			else {
				if (maxVal < m) {
					maxVal = m;
					maxIdx = ix;
				}
			}
		}
	}
	printf("%lld %lld\n", maxIdx, maxVal + 1);

	return 0;
}

void dfs(int r, int level) {
	visited[r] = 1;
	if (tree[r].first != 0) {
		dfs(tree[r].first, level + 1);
	}
	v[level].push_back(order++);
	if (tree[r].second != 0) {
		dfs(tree[r].second, level + 1);
	}
}

int searchRoot() {
	int arr[10001];
	for (int i = 1; i <= n; i++) {
		if (tree[i].first != 0)
			arr[tree[i].first] = 1;
		if (tree[i].second != 0)
			arr[tree[i].second] = 1;
	}

	int root;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != 1) {
			root = i;
			break;
		}
	}
	return root;
}

void insertNode(int root, int left, int right) {
	int i = 1;
	while(true) {
		if (i == root && tree[i].first == -1) {
			tree[i].first = left == -1 ? 0 : left;
			tree[i].second = right == -1 ? 0 : right;
			break;
		}
		i++;
	}
}
