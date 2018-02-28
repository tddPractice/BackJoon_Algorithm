/*

2018 Feb 28, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	char ch[20];
	for (int i = 0; i < 5; i++) {
		scanf("%s", ch);

		for (int j = 0; ch[j] != '\0'; j++) {
			if (ch[j] == 'F') {
				if (ch[j + 1] == 'B') {
					if (ch[j + 2] == 'I') {
						v.push_back(i + 1);
						break;
					}
				}
			}
		}
	}

	if (v.size()) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else {
		printf("HE GOT AWAY!\n");
	}
	return 0;
}