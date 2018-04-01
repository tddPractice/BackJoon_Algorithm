/*

2018 Apr 1, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	vector<int> a, b;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		a.push_back(k);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		b.push_back(k);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sum = 0;
	for (int i = 0, j = n -1; i < n; i++, j--) {
		sum += (a[i] * b[j]);
	}
	printf("%d\n", sum);
	return 0;
}
