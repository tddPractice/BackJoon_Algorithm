/*

2018 Feb 05, made by Moon

*/

#include <iostream>
#include <vector>

using namespace std;

void dp(vector<int> v, int j, int n, int m) {
	int posL = 1;
	int posR = m;
	int move = 0;

	for (int i = 1; i <= j; i++) {
		if (v[i - 1] < posL) {
			move += posL - v[i - 1];
			posL = v[i - 1];
			posR = posL + m - 1;
		}
		else if (v[i - 1] > posR) {
			move += v[i - 1] - posR;
			posR = v[i - 1];
			posL = posR - m + 1;
		}
		else {}
	}

	cout << move << endl;
}

int main() {
	int n, m, j;
	vector<int> v;

	cin >> n >> m;
	cin >> j;

	for (int i = 0; i < j; i++) {
		int pos;
		cin >> pos;
		v.push_back(pos);
	}

	dp(v, j, n, m);

	return 0;
}
