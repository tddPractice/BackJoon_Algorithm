/*

2018 Feb 24, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	sort(v.begin(), v.end());

	printf("%d\n", v[0] * v[2]);

	return 0;
}