/*

2018 Apr 29, made by Moon

*/
#include <cstdio>

#define MAX 11
using namespace std;

char ch[MAX];
int v[11] = { 0 };

int main() {
	scanf("%s", ch);

	for (int i = 0; ch[i] != '\0'; i++) {
		v[ch[i] - '0']++;
	}

	for (int i = 9; i >=0; i--) {
		if (v[i] != 0) {
			for (int j = 0; j < v[i]; j++) {
				printf("%d", i);
			}
		}
	}
	printf("\n");
	return 0;
}