/*

2018 Mar 1, made by Moon

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int alpha[26] = { 0 };
	char ch;

	while (scanf("%c", &ch) != EOF) {
		if (ch != ' ') {
			alpha[ch - 'a']++;
		}
	}

	int maxV = -1, maxIdx = -1;
	for (int i = 0; i < 26; i++) {
		maxV = maxV < alpha[i] ? alpha[i] : maxV;
	}

	vector<char> v;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == maxV) {
			v.push_back(i + 'a');
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		printf("%c", v[i]);
	}
	printf("\n");
	return 0;
}