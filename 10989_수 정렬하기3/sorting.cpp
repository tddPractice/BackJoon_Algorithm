/*

2018 Apr 29, made by Moon

*/
#include <cstdio>

#define MAX 10001
using namespace std;

int n;
int v[MAX] = { 0 };

int main() {
	scanf("%d", &n);

	while (n--) {
		int k;
		scanf("%d", &k);
		v[k]++;
	}

	for (int i = 1; i < MAX; i++) {
		if (v[i] > 0) {
			for (int j = 0; j < v[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}