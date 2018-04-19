/*

2018 Apr 20, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt;
	scanf("%d", &n);
	
	cnt = 0;
	while (n % 5 != 0 && n > 1) {
		cnt++;
		n -= 2;
	}

	if (n == 1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", cnt + (n / 5));
	}
	return 0;
}