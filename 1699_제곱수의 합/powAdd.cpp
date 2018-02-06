/*

2018 Feb 07, made by Moon

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool isSqrt(int n) {
	for (int i = 2; i <= n; i++) {
		if (i*i == n) return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	int dp[100001] = { 0, };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for (int i = 4; i <= n; i++) {
		if (sqrt(i) - (int)sqrt(i) == 0) {
			dp[i] = 1;
		}
		else {
			int minV = 98765432;
			for (int j = 1; j*j <= i; j++) {
				minV = min(minV, dp[j*j] + dp[i - (j*j)]);
			}
			dp[i] = minV;
		}
	}
	cout << dp[n] << endl;
	return 0;
}
