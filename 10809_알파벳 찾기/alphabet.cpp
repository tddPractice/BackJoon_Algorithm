/*

2018 Fb 25, made by Moon

*/
#include <cstdio>

int main() {
	int i, alpha[26] = { 0 };
	char c;
	char ch[101];
	scanf("%s", ch);

	for (i = 0; i < 26; i++) {
		alpha[i] = -1;
	}

	i = 0;
	while (ch[i] != '\0') {
		if (alpha[ch[i] - 'a'] == -1) {
			alpha[ch[i] - 'a'] = i;
		}
		i++;
	}

	for (i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);
	}
	printf("\n");
	return 0;
}