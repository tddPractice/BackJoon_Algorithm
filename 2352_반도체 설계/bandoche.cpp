/*

2018 Mar 9, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	int port1[40001] = { 0 };
	vector<int> lis;
	vector<int>:: iterator it;
	scanf("%d", &n);

	int size = 0;
	lis.push_back(-1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (lis.back() < k) {
			lis.push_back(k);
			size++;
		}
		else {
			it = lower_bound(lis.begin(), lis.end(), k);
			*it = k;
		}
	}

	printf("%d\n", size);
	return 0;
}