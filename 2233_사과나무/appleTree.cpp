/*

2018 May 12, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 99999
using namespace std;

int n, x, y;
int parent[MAX], idx[MAX];
char ch[MAX];

void findParents(int r, vector<int> &prnV) {
	int root = r;

	while (parent[root] != -1) {
		prnV.push_back(parent[root]);
		root = parent[root];
	}
}

int getCommRoot() {
	vector<int> prnX, prnY;

	prnX.push_back(x);
	prnY.push_back(y);

	findParents(x, prnX);
	findParents(y, prnY);

	int commRoot = 0;
	for (int i = 0; i < prnX.size(); i++) {
		for (int j = 0; j < prnY.size(); j++) {
			if (prnX[i] == prnY[j]) {
				commRoot = prnX[i];
				return commRoot;
			}
		}
	}

	return commRoot;
}

int main() {
	scanf("%d", &n);
	getchar();

	scanf("%s", ch);
	scanf("%d %d", &x, &y);

	int prn;
	vector<int> st;

	for (int i = 0; i < MAX; i++) {
		parent[i] = -1;
		idx[i] = -1;
	}
	idx[0] = 0;

	for (int i = 0, j = 0; ch[i] != '\0'; i++) {
		if (j == 0) {
			parent[j] = -1;
			st.push_back(j++);
			idx[j] = st.back();
		}
		else {
			if (ch[i] == '0') {
				prn = st.back();
				parent[j] = prn;
				st.push_back(j++);

				idx[i] = st.back();
			}
			else if (ch[i] == '1') {
				idx[i] = st.back();
				st.pop_back();
			}
		}
	}

	x = idx[x - 1];
	y = idx[y - 1];

	int commRoot = getCommRoot();

	for (int i = 0; ch[i] != '\0'; i++) {
		if (idx[i] == commRoot) {
			printf("%d ", i + 1);
			break;
		}
	}

	for (int i = 2 * n - 1; i >= 0; i--) {
		if (idx[i] == commRoot) {
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}