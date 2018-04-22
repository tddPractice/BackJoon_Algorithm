/*

2018 Apr 22, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, m, k;
	scanf("%d %d", &n, &k);

	vector<int> v;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		
		v.push_back(m);
	}

	int cur = 0, prev = v[0], cnt = 0;
	for (int i = 1; i < v.size(); i++) {
		cur = v[i] / prev;
		prev = v[i];
		cnt += k % cur;
		k /= cur;
	}

	if (k != 0) {
		cnt += k;
	}

	printf("%d\n", cnt);

	return 0;
}