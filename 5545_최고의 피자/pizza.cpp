/*

2018 Feb 19, made by Moon

*/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n, a, b, c;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &c);

	priority_queue<int> toping;
	int d;
	while (n--) {
		scanf("%d", &d);
		toping.push(d);
	}

	int maxV = c / a;
	int acc_c = c, acc_t = a;
	while (!toping.empty()) {
		acc_t += b;
		acc_c += toping.top();
		if ((acc_c / acc_t) < maxV) {
			break;
		}
		else {
			maxV = acc_c / acc_t;
			toping.pop();
		}
	}
	printf("%d\n", maxV);
	return 0;
}
