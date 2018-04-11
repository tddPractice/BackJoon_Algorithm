/*

2018 Apr 11, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

void permutation(int n, int pointer, vector<int> &v, vector<int> &list) {
	v[pointer]--;
	list.push_back(pointer);

	if (list.size() == n) {
		for (int i = 0; i < list.size(); i++) {
			printf("%d ", list[i]);
		}
		printf("\n");

		list.pop_back();
		v[pointer]++;
		return;
	}

	int nextPointer;
	
	for (int i = 1; i <= n; i++) {
		if (v[i] > 0) {
			nextPointer = i;
			permutation(n, nextPointer, v, list);
		}
	}

	list.pop_back();
	v[pointer]++;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> v(n + 1, 1);
	vector<int> list;

	for (int i = 1; i <= n; i++) {
		permutation(n, i, v, list);

		for (int j = 1; j <= n; j++) {
			v[j] = 1;
		}
		list.erase(list.begin(), list.end());
	}
	return 0;
}