/*

2018 Mar 1, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

vector<char> reverseStr(vector<char> v) {
	vector<char> tmp;

	for (int i = v.size() - 1; i >= 0; i--) {
		tmp.push_back(v[i]);
	}
	return tmp;
}

int main() {
	vector<char> v;
	char ch[101];
	scanf("%s", ch);
	
	for (int i = 0; ch[i] != '\0'; i++) {
		v.push_back(ch[i]);
	}

	v = reverseStr(v);

	while (v.size() % 3 != 0) {
		v.push_back('0');
	}

	v = reverseStr(v);

	int res = 0;
	for (int i = 0, k = 1; i < v.size(); k *= 2, i += 3) {
		if (v[i] == '0') {
			if (v[i + 1] == '0') {
				if (v[i + 2] == '0') {
					printf("0");
				}
				else {
					printf("1");
				}
			}
			else {
				if (v[i + 2] == '0') {
					printf("2");
				}
				else {
					printf("3");
				}
			}
		}
		else {
			if (v[i + 1] == '0') {
				if (v[i + 2] == '0') {
					printf("4");
				}
				else {
					printf("5");
				}
			}
			else {
				if (v[i + 2] == '0') {
					printf("6");
				}
				else {
					printf("7");
				}
			}
		}
	}

	printf("\n");
	return 0;
}