/*

2018 Mar 22, made by Moon

*/
#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int cnt = 0, sum = 0;
		char ch[81];
		scanf("%s", ch);

		for (int j = 0; ch[j] != '\0'; j++) {
			if (ch[j] == 'O') {
				cnt++;
			}
			else {
				cnt = 0;
			}
			sum += cnt;
		}
		printf("%d\n", sum);
	}
	return 0;
}