/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int main() {
	char ch[101];
	scanf("%s", ch);

	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] >= 'A' && ch[i] <= 'Z') {
			printf("%c", ch[i]);
		}
	}
	printf("\n");
	return 0;
}