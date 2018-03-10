/*

2018 Mar 10, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int convertToInt(char chNum[51]) {
	int num = 0, n = 1, i = 0;
	for (int j = 0; chNum[j] != '\0'; j++) {
		i++;
	}
	i--;
	while (i >= 0) {
		if (chNum[i] == '-' || chNum[i] == '+') {
			break;
		}
		num += (chNum[i] - '0') * n;
		i--;
		n *= 10;
	}
	if (chNum[0] == '-') {
		return -num;
	}
	return num;
}

int main() {
	int n, i;
	char ch[51];
	vector<int> num;

	scanf("%s", ch);
	for (i = 0; ch[i] != '\0'; i++) {

		char chNum[51];
		int k = 0, j = i;
		do {
			chNum[k++] = ch[j];
			i++;
			j++;
		} while (ch[j] != '-' && ch[j] != '+' && ch[j] != '\0');
		chNum[k] = '\0';
		i--;
		num.push_back(convertToInt(chNum));
	}

	int sum = 0;
	i = 0;
	while (i < num.size() && num[i] >= 0) {
		sum += num[i++];
	}
	for (int j = i; j < num.size(); j++) {
		if (num[j] > 0) {
			sum += -num[j];
		}
		else {
			sum += num[j];
		}
	}
	printf("%d\n", sum);
	return 0;
}