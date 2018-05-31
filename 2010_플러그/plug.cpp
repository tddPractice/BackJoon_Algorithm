/*

2018 May 31, made by Moon

*/
#include <cstdio>
using namespace std;

int n, sum;

int main() {
	scanf("%d", &n);

	sum = 0;

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		sum += k;
	}
	sum -= (n - 1);

	printf("%d\n", sum);
	return 0;
}