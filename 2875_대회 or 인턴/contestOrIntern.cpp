/*

2018 Feb 22, made by Moon

*/
#include <cstdio>

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int maxV = 0;
	for (int i = 0; i <= k; i++) {
		int boy, girl, teamN;
		boy = n;
		girl = m;

		boy -= i;
		girl -= (k - i);
		if (girl != 0 && boy != 0) {
			teamN = boy / 2 > girl ? girl : boy / 2;
		}
		else {
			teamN = 0;
		}
		maxV = maxV > teamN ? maxV : teamN;

	}

	printf("%d\n", maxV);

	return 0;
}