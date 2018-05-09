/*

2018 May 10, made by Moon

*/
#include <cstdio>

#define MAX 2501
#define SMAX 51
using namespace std;

char ch[MAX];
char search[SMAX];

bool cmp(int r) {
	int i, j;
	for (i = 0, j = r; search[i] != '\0' && ch[j] != '\0'; i++, j++) {
		if (search[i] != ch[j]) {
			return false;
		}
	}

	if (search[i] != '\0' && ch[j] == '\0') {
		return false;
	}

	return true;
}

int main() {
	int i = 0;
	char c;
	while (true) {
		scanf("%c", &c);

		if (c == '\n' || c == EOF) {
			break;
		}

		ch[i++] = c;
	}
	ch[i] = '\0';

	i = 0;
	while (true) {
		scanf("%c", &c);

		if (c == '\n' || c == EOF) {
			break;
		}

		search[i++] = c;
	}
	search[i] = '\0';

	int match = 0;
	int size = 0;
	
	for (i = 0; search[i] != '\0'; i++) {
		size++;
	}

	for (i = 0; ch[i] != '\0'; i++) {
		if (cmp(i)) {
			match++;
			i = i + size - 1;
		}
	}
	printf("%d\n", match);

	return 0;
}