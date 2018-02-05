/*

2018 Feb 05, made by Moon

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		v.push_back(l);
	}

	sort(v.begin(), v.end());
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
		max = max < v[i] * (n - i) ? v[i] * (n - i) : max;
	}

	printf("%d\n", max);

	return 0;
}
