/*

2018 Apr 11, made by Moon

*/
#include <cstdio>
#include <vector>
#define MAX 50
using namespace std;

void permutation(int pointer, vector<int> &v, vector<int> &list) {
	v[pointer] = 0;
	list.push_back(pointer);

	if (list.size() == 6) {
		for (int i = 0; i < list.size(); i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
	}
	else {
		int nextPointer;

		for (int i = 1; i <= MAX; i++) {
			if (v[i] > 0) {
				if (list.size()) {
					if (list.back() < i) {
						nextPointer = i;
						permutation(nextPointer, v, list);
						v[nextPointer] = 1;
						list.pop_back();
					}
				}else{
					nextPointer = i;
					permutation(nextPointer, v, list);
					v[nextPointer] = 1;
					list.pop_back();
				}
			}
		}
	}

}

void permutationAll(int n) {
	int k, maxN;
	vector<int> v(MAX + 1, 0), list;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		v[k] = 1;
	}

	int cnt = n;
	for (int i = 1; i <= MAX; i++) {
		if (v[i] > 0 && cnt >= 6) {
			cnt--;
			permutation(i, v, list);

			list.erase(list.begin(), list.end());
		}
	}
}

int main() {
	while (true) {
		int n, k;

		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		permutationAll(n);
		printf("\n");
	}
	return 0;
}