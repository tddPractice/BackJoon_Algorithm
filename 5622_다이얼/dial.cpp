/*

2018 Feb 25, made by Moon

*/
#include <cstdio>
#include <map>
using namespace std;

map<char, int> m;

void initMap(){
	m['A'] = m['B'] = m['C'] = 2;
	m['D'] = m['E'] = m['F'] = 3;
	m['G'] = m['H'] = m['I'] = 4;
	m['J'] = m['K'] = m['L'] = 5;
	m['M'] = m['N'] = m['O'] = 6;
	m['P'] = m['Q'] = m['R'] = m['S'] = 7;
	m['T'] = m['U'] = m['V'] = 8;
	m['W'] = m['X'] = m['Y'] = m['Z'] = 9;
}

int main() {
	initMap();

	char ch[16];
	scanf("%s", ch);

	int time = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		time +=	m[ch[i]] + 1;
	}
	printf("%d\n", time);
	return 0;
}