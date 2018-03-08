/*

2018 Mar 8, made by Moon

*/
#include <cstdio>

int main() {
	int i = 0;
	char ch[256];
	char c;
	while (scanf("%c", &c) != EOF) {
		ch[i] = c;
		i++;
	}

	int happyN = 0;
	int sadN = 0;
	int emoti = 0;
	for (i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == ':') {
			if (emoti == 0) {
				emoti++;
			}
			else {
				emoti = 1;
			}
		}
		else if (ch[i] == '-') {
			if (emoti == 1) {
				emoti++;
			}
			else {
				emoti = 0;
			}
		}
		else if (ch[i] == ')') {
			if (emoti == 2) {
				happyN++;
			}
			emoti = 0;
		}
		else if (ch[i] == '(') {
			if (emoti == 2) {
				sadN++;
			}
			emoti = 0;
		}
	}

	if (happyN == 0 && sadN == 0) {
		printf("none\n");
	}
	else if (happyN == sadN) {
		printf("unsure\n");
	}
	else if (happyN > sadN) {
		printf("happy\n");
	}
	else {
		printf("sad\n");
	}
	return 0;
}