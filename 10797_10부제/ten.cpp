/*

2018 Apr 14, made by Moon

*/
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, k;
	vector<int> v;
	map<int, int> m;
	scanf("%d", &n);

	for (int i = 1; i <= 5; i++) {
		scanf("%d", &k);
		v.push_back(k);
		int j = k;
		while (j <= 31) {
			m[j] = 1;
			j += 10;
		}
	}

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == n) {
			int j = v[i];
			while (j <= 31) {
				if (m[j] == 1) {
					cnt++;
					break;
				}
				j += 10;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}