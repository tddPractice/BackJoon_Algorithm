/*

2018 Feb 19, made by Moon

*/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int k;
	priority_queue<int> q;
	while (t--) {
		scanf("%d", &k);
		q.push(k);
	}

	long long res = 0, i = 1;
	while (!q.empty()) {
		int tip = q.top() - (i - 1);
		if (tip < 0) {
			break;
		}
		res += tip;
		q.pop();
		i++;
	}

	printf("%lld\n", res);
	return 0;
}
