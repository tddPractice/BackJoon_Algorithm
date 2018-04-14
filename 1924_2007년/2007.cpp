/*

2018 Apr 14, made by Moon

*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int m, d;
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string date[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	cin >> m >> d;

	int days = d;
	for (int i = 1; i < m; i++) {
		days += month[i];
	}

	cout << date[days % 7] << endl;
	return 0;
}