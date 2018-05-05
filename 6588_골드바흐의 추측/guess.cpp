/*

2018 May 5, made by Moon

*/
#include <cstdio>

#define MAX 1000001
using namespace std;

int n, v[MAX] = { 0 };

int main() {
	v[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = 2; j * i < MAX; j++) {
			v[i * j] = 1;
		}
	}

	while (true) {
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		int a = 0, b = 0;
		for (int i = 2; i < n; i++) {
			if (v[i] == 0 && v[n - i] == 0) {
				a = i;
				b = n - i;
				break;
			}
		}

		if (a == 0 || b == 0) {
			printf("Goldbach's conjecture is wrong.\n");
		}
		else {
			printf("%d = %d + %d\n", n, a, b);
		}
	}

	return 0;
}