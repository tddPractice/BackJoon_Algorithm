/*

2018 Apr 23, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d", &n);

	vector<int> v, v2;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);

		if (k > 0) {
			v.push_back(k);
		}
		else {
			v2.push_back(k);
		}
	}

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	int sum = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i >= 1) {
			if (v[i] + v[i - 1] < v[i] * v[i - 1]) {
				sum += v[i] * v[i - 1];
				i--;
			}
			else {
				sum += v[i];
			}
		}
		else {
			sum += v[i];
		}
	}

	int v2Size = v2.size();
	for (int i = 0; i < v2Size; i++) {
		if (i <= v2Size - 2) {
			if (v2[i] + v2[i + 1] < v2[i] * v2[i + 1]) {
				sum += v2[i] * v2[i + 1];
				i++;
			}
			else {
				sum += v2[i];
			}
		}
		else {
			sum += v2[i];
		}
	}

	printf("%d\n", sum);
	return 0;
}