/*

2018 Mar 20, made by Moon

*/
#include <cstdio>

int pow(int n, int p) {
	int s, e, sPow, ePow;
	s = n / 10;
	e = n % 10;
	
	sPow = 1;
	ePow = 1;

	if (s >= 10) {
		sPow = pow(s, p);
		for (int i = 1; i <= p; i++) {
			ePow = ePow * e;
		}
	}
	else {
		for (int i = 1; i <= p; i++) {
			sPow = sPow * s;
			ePow = ePow * e;
		}
	}
	return sPow + ePow;
}

int main() {
	int a, p, d, firstDistN, cnt;
	int list[1000000] = { 0 }, dist[1000000] = { 0 };
	scanf("%d %d", &a, &p);

	d = a;
	list[d] = 1;

	while (true) {
		d = pow(d, p);
		if (list[d] == 1) {
			firstDistN = d;
			dist[firstDistN] = 1;
			break;
		}
		else {
			list[d] = 1;
		}
	}

	do {
		d = pow(d, p);
		dist[d] = 1;
	} while (firstDistN != d);

	cnt = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (list[i] == 1 && dist[i] == 0) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}