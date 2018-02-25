/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int main() {
	int alpha[26] = { 0 };
	char ch[101];
	scanf("%s", ch);

	for (int i = 0; ch[i] != '\0'; i++) {
		alpha[ch[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);
	}
	printf("\n");
	return 0;
}