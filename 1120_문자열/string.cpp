/*

2018 Feb 22, made by Moon

*/
#include <cstdio>

int main() {
	char chA[50];
	char chB[50];
	for (int i = 0; i < 2; i++) {
		if (i == 0)
			scanf("%s", chA);
		else
			scanf("%s", chB);
	}

	int sizeA = 0, sizeB = 0;
	for (int i = 0; chA[i] != '\0'; ++i) {
		sizeA++;
	}
	for (int i = 0; chB[i] != '\0'; ++i) {
		sizeB++;
	}

	int minV = 98765432;
	int diff = 0;

	for (int i = 0; i < sizeB; i++) {
		if (sizeB - i >= sizeA) {
			for (int j = i, k = 0; j < sizeB; j++, k++) {
				if (chA[k] == '\0' || chB[j] == '\0') {
					break;
				}
				else {
					if (chA[k] != chB[j]) {
						diff++;
					}
				}
			}
			minV = minV > diff ? diff : minV;
			diff = 0;
		}
	}

	printf("%d\n", minV);

	return 0;
}