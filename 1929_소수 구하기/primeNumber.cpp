/*

2018 Mar 20, made by Moon

*/

//Sieve of Eratosthenes
#include <cstdio>

int main() {
	int m, n;
	int arr[1000001] = { 0 };
	scanf("%d %d", &m, &n);

	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; i * j <= 1000000; j++) {
			arr[i*j] = 1;
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}