/*

2018 Apr 14, made by Moon

*/
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, int> m1, m2, res;

int main() {
	int n, m;
	string s;
	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 1; i <= n; i++) {
		cin >> s;
		m1[s] = 1;
	}

	for (int i = 1; i <= m; i++) {
		cin >> s;
		m2[s] = 1;
	}

	int cnt = 0;
	map<string, int>::iterator itMap;
	for (itMap = m1.begin(); itMap != m1.end(); itMap++) {
		if (m2[itMap->first] == 1) {
			cnt++;
			res[itMap->first] = 1;
		}
	}

	cout << cnt << endl;
	for (itMap = res.begin(); itMap != res.end(); itMap++) {
		cout << itMap->first << endl;
	}
	return 0;
}