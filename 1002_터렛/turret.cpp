/*

2018 Mar 23, made by Moon

*/
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d", &n);

	while (n--) {
		int x1, y1, x2, y2, r1, r2;
		int dist;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		dist = (x1 - x2) * (x1 - x2) + (y1 - y2) *  (y1 - y2);
		
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			printf("-1\n");
		}
		else {
			if (dist > (r1  + r2) * (r1 + r2)) {
				printf("0\n");
			}
			else if (dist == (r1 + r2) * (r1 + r2)) {
				printf("1\n");
			}
			else if (dist == (max(r1, r2) - min(r1, r2)) * (max(r1, r2) - min(r1, r2))) {
				printf("1\n");
			}
			else if (dist < (max(r1, r2) - min(r1, r2)) * (max(r1, r2) - min(r1, r2))) {
				printf("0\n");
			}
			else {
				printf("2\n");
			}
		}
	}
	return 0;
}