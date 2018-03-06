/*

2018 Mar 6, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	vector<int> v1, v2;
	vector<int> vec;
	scanf("%d %d", &n, &m);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v1.push_back(a);
		v2.push_back(b);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int k;
	int minV = 98765432;
	if (n <= 6) {
		minV = min(v1.front(), v2.front() * n);
	}
	else {
		if (n % 6 == 0) {
			minV = min(v1.front() * (n / 6), v2.front() * n);
		}
		else {
			minV = min(v1.front() * (n / 6) + v2.front() * (n % 6), min(v2.front() * n, v1.front() * (n / 6 + 1)));
		}
	}

	printf("%d\n", minV);
	return 0;
}