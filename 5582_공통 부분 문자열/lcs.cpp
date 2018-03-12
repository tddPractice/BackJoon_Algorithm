/*

2018 Mar 12, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char ch1[4001], ch2[4001];
	vector<vector<int> > lcs;

	scanf("%s", ch1);
	scanf("%s", ch2);

	int i, j;
	for (i = 0; ch1[i] != '\0'; i++) {
		vector<int> v;
		lcs.push_back(v);
		for (j = 0; ch2[j] != '\0'; j++) {
			lcs[i].push_back(0);
		}
		lcs[i].push_back(0);
	}

	vector<int> t;
	lcs.push_back(t);
	for (j = 0; ch2[j] != '\0'; j++) {
		lcs[i].push_back(0);
	}
	lcs[i].push_back(0);

	//lcs
	for (i = 0; ch1[i] != '\0'; i++) {
		for (j = 0; ch2[j] != '\0'; j++) {
			if (ch1[i] == ch2[j]) {
				lcs[i + 1][j + 1] = lcs[i][j] + 1;
			}
			else {
				lcs[i + 1][j + 1] = 0;
			}
		}
	}

	int maxV = -1;
	for (i = 0; ch1[i] != '\0'; i++) {
		for (j = 0; ch2[j] != '\0'; j++) {
			maxV = max(lcs[i + 1][j + 1], maxV);
		}
	}

	printf("%d\n", maxV);
	
	return 0;
}