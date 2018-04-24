/*

2018 Apr 24, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	char ch;

	while (true) {
		scanf("%c", &ch);

		if (ch == EOF || ch == '\0' || ch == '\n') {
			break;
		}

		v.push_back(ch - '0');
	}

	sort(v.begin(), v.end());

	if (v[0] != 0) {
		printf("-1\n");
	}
	else {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}

		if (sum % 3 != 0) {
			printf("-1\n");
			return 0;
		}

		reverse(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			printf("%d", v[i]);
		}
		printf("\n");
	}

	return 0;
}