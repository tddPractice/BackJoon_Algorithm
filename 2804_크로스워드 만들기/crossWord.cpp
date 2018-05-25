/*

2018 May 25, made by Moon

*/
#include <cstdio>
#include <queue>

using namespace std;

char chA[31], chB[31], chRes[31][31];

void print(int n, int m) {
	for (int i = 0; chB[i] != '\0'; i++) {
		chRes[i][n] = chB[i];
	}

	for (int j = 0; chA[j] != '\0'; j++) {
		chRes[m][j] = chA[j];
	}

	for (int i = 0; chB[i] != '\0'; i++) {
		for (int j = 0; chA[j] != '\0'; j++) {
			printf("%c", chRes[i][j]);
		}
		printf("\n");
	}
}

void check() {
	for (int i = 0; chA[i] != '\0'; i++) {
		for (int j = 0; chB[j] != '\0'; j++) {
			if (chA[i] == chB[j]) {
				print(i, j);
				return;
			}
		}
	}
}

int main() {
	scanf("%s %s", chA, chB);

	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			chRes[i][j] = '.';
		}
	}

	check();

	return 0;
}