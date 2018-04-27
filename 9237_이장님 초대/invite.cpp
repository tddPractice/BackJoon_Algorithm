/*

2018 Apr 28, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d", &n);

	vector<int> v, list;

	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);

		v.push_back(k);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int cnt = 2, maxV = -1;
	int size = v.size();

	for (int i = 0; i < size; i++) {
		v[i] += cnt++;
		maxV = max(maxV, v[i]);
	}

	printf("%d\n", maxV);
	return 0;
}