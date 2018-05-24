/*

2018 May 24, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 10000
using namespace std;

int m, n;
vector<int> v;

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= MAX; i++) {
		v.push_back(i*i);
	}

	int sum = 0, min = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > n) {
			break;
		}
		else {
			if (v[i] >= m) {
				sum += v[i];

				if (min == -1) {
					min = v[i];
				}
			}
		}
	}

	if (sum == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n%d\n", sum, min);
	}

	return 0;
}