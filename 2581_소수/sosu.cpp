/*

2018 Apr 16, made by Moon

*/
#include <cstdio>

int main() {
	int n, m;
	int v[10001] = { 0 };
	
	v[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		for (int j = 2; i * j <= 10000; j++) {
			v[i * j] = 1;
		}
	}

	scanf("%d %d", &n, &m);

	int s, e;
	int sum = 0;
	int min = 99999;

	s = n > m ? m : n;
	e = n > m ? n : m;
	
	for (int i = s; i <= e; i++) {
		if (!v[i]) {
			sum += i;
			
			if (min == 99999) {
				min = i;
			}
		}
	}

	if (sum != 0) {
		printf("%d\n%d\n", sum, min);
	}
	else {
		printf("-1\n");
	}
	return 0;
}