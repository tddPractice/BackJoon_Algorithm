/*

2018 Mar 1, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	char alpha[26];
	vector<char> v;
	vector<char> pw;
	char ch;

	for (int i = 0; i < 26; i++) {
		alpha[i] = 'a' + i;
	}

	while (scanf("%c", &ch) != EOF && ch != '\0' && ch != '\n') {
		v.push_back(ch);
	}

	while (scanf("%c", &ch) != EOF && ch != '\0' && ch != '\n') {
		pw.push_back(ch);
	}

	for (int i = 0, k = 0; i < v.size(); i++) {
		if (v[i] == ' ') {
			printf(" ");
		}
		else {
			if (v[i] > pw[k]) {
				printf("%c", alpha[v[i] - pw[k] - 1]);
			}
			else if (v[i] == pw[k]) {
				printf("z");
			}
			else {
				printf("%c", alpha[25 - (pw[k] - v[i])]);
			}
		}
		if (k == pw.size() - 1) {
			k = 0;
		}
		else {
			k++;
		}
	}

	return 0;
}