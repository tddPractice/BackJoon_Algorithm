/*

2018 Mar 1, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char ch[1001], ch2[1001];
	vector<int> c, c2;

	scanf("%s", ch);
	scanf("%s", ch2);

	for (int i = 0; ch[i] != '\0'; i++) {
		c.push_back(0);
	}

	for (int i = 0; ch2[i] != '\0'; i++) {
		c2.push_back(0);
	}

	for (int i = 0; ch[i] != '\0'; i++) {
		for (int j = 0; ch2[j] != '\0'; j++) {
			if (c[i] == 0 && c2[j] == 0 && ch[i] == ch2[j]) {
				c[i] = 1;
				c2[j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == 0) {
			cnt++;
		}
	}

	for (int i = 0; i < c2.size(); i++) {
		if (c2[i] == 0) {
			cnt++;
		}
	}

	vector<char> v1, v2;
	printf("%d\n", cnt);
	return 0;
}