/*

2018 Mar 4, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	scanf("%d", &n);

	v.push_back(0); // 0
	v.push_back(1); // 1
	v.push_back(2); // 2
	v.push_back(3); // 3
	v.push_back(5); // 4

	int k;
	for (int i = 5; i <= n; i++) {
		k = (v[i - 1] + v[i - 2]) % 15746;
		v.push_back(k);
	}

	printf("%d\n", v[n]);
	return 0;
}