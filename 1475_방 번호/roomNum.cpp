/*

2018 Feb 25, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	int num[10] = { 0 };
	scanf("%d", &n);

	int k;
	do {
		k = n % 10;
		n /= 10;

		if (k == 6 || k == 9) {
			num[6]++;
			num[9]++;
		}
		else {
			num[k]++;
		}
	} while (n != 0);

	int maxV = 0;
	num[6] = num[6] / 2 + num[6] % 2;
	num[9] = num[9] / 2 + num[9] % 2;
	for (int i = 0; i < 10; i++) {
		maxV = maxV > num[i] ? maxV : num[i];
	}
	printf("%d\n", maxV);

	return 0;
}