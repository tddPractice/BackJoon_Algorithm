/*

2018 Feb 05, made by Moon

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp;
	dp.push_back(99999); // 0 -> 1
	dp.push_back(0); // 1 -> 1
	dp.push_back(1); // 2 -> 1
	dp.push_back(1); // 3 -> 1
	for (int i = 4; i <= n; i++) {
		int _div3 = 0, _div2 = 0, _minus1 = 0;
		int minV;
		
		if (i % 3 == 0) {
			_div3 = i / 3;
		}
		if (i % 2 == 0) {
			_div2 = i / 2;
		}
		_minus1 = i - 1;
		

		minV = min(dp[_div3], min(dp[_div2], dp[_minus1])) + 1;
		dp.push_back(minV);
	}

	cout << dp[n] << endl;

	return 0;
}
