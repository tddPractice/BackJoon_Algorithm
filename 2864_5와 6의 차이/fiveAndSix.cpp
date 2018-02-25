/*

2018 Feb 25, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

// mode - 1 : maxV함수에서 부름, 0 : minV함수에서 부름
int checkNumber(int n, char mode) {
	int tmp = n;
	vector<int> v;
	int k;

	do {
		k = tmp % 10;
		tmp /= 10;
		v.push_back(k);
	} while (tmp != 0);

	int res = 0;
	for (int i = 0, k = 1; i < v.size(); i++, k *= 10) {
		if (v[i] == 5 || v[i] == 6) {
			if (mode == 1) {
				v[i] = 6;
			}
			else if(mode == 0){
				v[i] = 5;
			}
		}
		res += k * v[i];
	}
	return res;
}

void getMin(int a, int b) {
	int bigN = a > b ? a : b;
	int smN = a > b ? b : a;

	int resBig = checkNumber(bigN, 0);
	int resSm = checkNumber(smN, 0);
	printf("%d", resBig + resSm);
}

void getMax(int a, int b) {
	int bigN = a > b ? a : b;
	int smN = a > b ? b : a;

	int resBig = checkNumber(bigN, 1);
	int resSm = checkNumber(smN, 1);
	printf("%d", resBig + resSm);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	getMin(a, b);
	printf(" ");
	getMax(a, b);
	printf("\n");
	return 0;
}