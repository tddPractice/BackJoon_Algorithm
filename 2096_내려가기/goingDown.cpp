/*

2018 Apr 7, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, c;
	int minDP[3] = { 0 }, maxDP[3] = { 0 };
	int tmp[3] = { 0 };
	scanf("%d", &n);

	scanf("%d %d %d", &a, &b, &c);

	minDP[0] = a;  maxDP[0] = a;
	minDP[1] = b;  maxDP[1] = b;
	minDP[2] = c;  maxDP[2] = c;

	for (int i = 2; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		//max
		tmp[0] = max(maxDP[0], maxDP[1]) + a;
		tmp[1] = max(maxDP[0], max(maxDP[1], maxDP[2])) + b;
		tmp[2] = max(maxDP[1], maxDP[2]) + c;

		maxDP[0] = tmp[0];
		maxDP[1] = tmp[1];
		maxDP[2] = tmp[2];

		//min
		tmp[0] = min(minDP[0], minDP[1]) + a;
		tmp[1] = min(minDP[0], min(minDP[1], minDP[2])) + b;
		tmp[2] = min(minDP[1], minDP[2]) + c;
		
		minDP[0] = tmp[0];
		minDP[1] = tmp[1];
		minDP[2] = tmp[2];
	}

	printf("%d %d\n", max(maxDP[0], max(maxDP[1], maxDP[2])), min(minDP[0], min(minDP[1], minDP[2])));
	return 0;
}