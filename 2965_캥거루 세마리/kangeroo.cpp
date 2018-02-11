/*

2018 Feb 11, made by Moon

*/
#include <cstdio>
#include <algorithm>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int cnt = 0;
	int temp;
	while (true) {
		if ((a - b == 1 || a - b == -1) && (b - c == 1 || b - c == -1)) {
			break;
		}

		int left = b > a ? b - a : a - b;
		int right = c > b ? c - b : b - c;
		if (left <= right) {
			cnt++;
			a = b + 1;
			temp = b;
			b = a;
			a = temp;
		}
		else{
			cnt++;
			c = b - 1;
			temp = b;
			b = c;
			c = temp;
		}
	}
	printf("%d\n", cnt);
}