/*

2018 May 17, made by Moon

*/
#include <cstdio>

using namespace std;

int x, y, w, h;

int main() {

	scanf("%d %d %d %d", &x, &y, &w, &h);

	int a, b;

	if (w - x > x) {
		a = x;
	}
	else {
		a = w - x;
	}

	if (h - y > y) {
		b = y;
	}
	else {
		b = h - y;
	}

	printf("%d\n", a > b ? b : a);

	return 0;
}