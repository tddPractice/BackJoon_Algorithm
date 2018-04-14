/*

2018 Apr 14, made by Moon

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	char ch, v[16][16] = { '0' };

	for (int i = 1; i <= 5; i++) {
		scanf("%s", v[i]);
	}

	string s = "";
	for (int i = 0; i <= 15; i++) {
		for (int j = 1; j <= 5; j++) {
			if (v[j][i] != '\0') {
				s += v[j][i];
			}
		}
	}

	cout << s << endl;

	return 0;
}