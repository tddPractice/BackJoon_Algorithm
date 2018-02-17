/*

2018 Feb 17, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> v;
vector<int> cmp;
int main() {
	scanf("%d", &n);

	int k;
	while (n--) {
		scanf("%d", &k);
		v.push_back(k);
		cmp.push_back(0);
	}

	int maxV = 0, size = v.size();
	for (int i = size - 1; i >= 0; i--) {
		for (int j = i + 1; j < size; j++) {
			if (v[i] < v[j]) {
				maxV = maxV < cmp[j] ? cmp[j] : maxV;
			}
		}
		maxV++;
		cmp[i] = maxV;
		maxV = 0;
	}

	maxV = -1;
	for (int i = 0; i < cmp.size(); i++) {
		//printf("%d ", cmp[i]);
		maxV = maxV < cmp[i] ? cmp[i] : maxV;
	}
	printf("%d\n", maxV);

	return 0;
}
