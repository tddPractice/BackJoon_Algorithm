/*

2018 Feb 28, made by Moon

*/
#include <cstdio>

bool checkJOI(char ch[], int i) {
	if (ch[i] == 'J' && ch[i + 1] == 'O' && ch[i + 2] == 'I')
		return true;
	return false;
}

bool checkIOI(char ch[], int i) {
	if (ch[i] == 'I' && ch[i + 1] == 'O' && ch[i + 2] == 'I')
		return true;
	return false;
}

int main() {
	char ch[10001];
	scanf("%s", ch);

	int joi = 0;
	int ioi = 0;

	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == 'J') {
			if (checkJOI(ch, i)) {
				joi++;
				i += 1;
			}
		}
		else if (ch[i] == 'I') {
			if (checkIOI(ch, i)) {
				ioi++;
				i += 1;
			}
		}
	}
	printf("%d\n%d\n", joi, ioi);
	return 0;
}