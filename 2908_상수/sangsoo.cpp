/*

2018 Feb 25, made by Moon

*/
#include <cstdio>

int convertToStr(int n) {
	int res;
	int reversed[3];

	reversed[0] = n % 10;

	n -= reversed[0];
	n /= 10;

	reversed[1] = n % 10;
	reversed[2] = n / 10;
	res = reversed[0] * 100 + reversed[1] * 10 + reversed[2];
	return res;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int num1 = convertToStr(a);
	int num2 = convertToStr(b);

	printf("%d\n", num1 > num2 ? num1 : num2);

	return 0;
}