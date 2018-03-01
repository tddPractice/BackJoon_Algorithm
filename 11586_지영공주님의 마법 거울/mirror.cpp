/*

2018 Mar 1, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

void printV(vector<vector<char> > v, int m) {
	if (m == 1) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				printf("%c", v[i][j]);
			}
			printf("\n");
		}
	}
	else if (m == 2) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = v[i].size() - 1; j >= 0; j--) {
				printf("%c", v[i][j]);
			}
			printf("\n");
		}
	}
	else {
		for (int i = v.size() - 1; i >= 0; i--) {
			for (int j = 0; j < v[i].size(); j++) {
				printf("%c", v[i][j]);
			}
			printf("\n");
		}
	}
}

int main() {
	int n;
	char ch;
	vector<vector<char> > v;
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		v.push_back(vector<char>());
		for (int j = 0; j < n; j++) {
			scanf("%c", &ch);
			v[i].push_back(ch);
		}
		getchar();
	}

	int m;
	scanf("%d", &m);

	printV(v, m);
	return 0;
}