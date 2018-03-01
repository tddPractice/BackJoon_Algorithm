/*

2018 Mar 1, made by Moon

*/
#include <cstdio>

int main() {
	int n = 1;
	char ch[3];
	scanf("%s", ch);

	if (ch[1] == '\0') {
		n = ch[0] - '0';
	}
	else {
		n = ((ch[0] - '0') * 10) + (ch[1] - '0');
	}

	int newN = n, cnt = 0, sum;
	while (true) {
		int c[2];

		if (newN < 10) {
			c[0] = 0;
			c[1] = newN;
		}
		else {
			c[0] = newN / 10;
			c[1] = newN % 10;
		}

		sum = c[0] + c[1];

		c[0] = c[1];
		c[1] = sum % 10;
		newN = c[0] * 10 + c[1];
		cnt++;
		if (newN == n) {
			break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}