/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);

	int cnt = 0;
	while (t--) {
		int visited[101] = { 0 };
		char ch[101];
		scanf("%s", ch);

		for (int i = 0; ch[i] != '\0'; i++) {
			if (i == 0) {
				visited[ch[i] - 'a'] = 1;
			}
			else {
				if (visited[ch[i] - 'a'] == 0) {
					visited[ch[i] - 'a'] = 1;
				}
				else {
					if (ch[i] != ch[i - 1]) {
						cnt--;
						break;
					}
				}
			}
		}
		cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}