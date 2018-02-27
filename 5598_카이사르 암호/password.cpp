/*

2018 Feb 27, made by Moon

*/
#include <cstdio>

int main() {
	char ch[1001];
	scanf("%s", ch);

	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == 'A') {
			printf("X");
		}
		else if (ch[i] == 'B') {
			printf("Y");
		}
		else if (ch[i] == 'C') {
			printf("Z");
		}
		else {
			printf("%c", ch[i] - 3);
		}
	}
	printf("\n");
	return 0;
}