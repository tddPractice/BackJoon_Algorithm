#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	int k;
	vector<int> v;
	vector<int> dpLeft;
	vector<int> dpRight;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		v.push_back(k);
		dpLeft.push_back(0);
		dpRight.push_back(0);
	}

	int maxV = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			if (v[i] > v[j])
				maxV = max(maxV, dpLeft[j]);
		}
		maxV++;
		dpLeft[i] = maxV;
		maxV = 0;
	}

	maxV = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (v[i] > v[j])
				maxV = max(maxV, dpRight[j]);
		}
		maxV++;
		dpRight[i] = maxV;
		maxV = 0;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, dpLeft[i] + dpRight[i]);
	}
	printf("%d\n", res - 1);
	return 0;
}
