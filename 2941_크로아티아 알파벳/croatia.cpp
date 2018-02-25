/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int main() {
	char ch[101];
	scanf("%s", ch);

	int cnt = 0;
	int isCroatia = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		switch (ch[i]) {
			case 'c':
				if (ch[i + 1] == '-' || ch[i + 1] == '=') {
					isCroatia = 1;
				}
				break;
			case 'd':
				if (ch[i + 1] == '-') {
					isCroatia = 1;
				}
				else if (ch[i + 1] == 'z') {
					if (ch[i + 2] == '=') {
						isCroatia = 1;
						i++;
					}
				}
				break;
			case 'l': case 'n':
				if (ch[i + 1] == 'j') {
					isCroatia = 1;
				}
				break;
			case 's': case 'z':
				if (ch[i + 1] == '=') {
					isCroatia = 1;
				}
				break;
			default:
				break;
		}
		if (isCroatia) {
			cnt++;
			i++;
		}
		else {
			cnt++;
		}
		isCroatia = 0;
	}

	printf("%d\n", cnt);
	return 0;
}