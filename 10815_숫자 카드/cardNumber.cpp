/*

2018 May 1, made by Moon

*/
#include <cstdio>
#include <map>

using namespace std;

int n, t;
map<int, int> m;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		m[k] = 1;
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int k;
		scanf("%d", &k);

		if (m[k]) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
	printf("\n");

	return 0;
}