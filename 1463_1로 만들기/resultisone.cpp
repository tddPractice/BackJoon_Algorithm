#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1000001];

int findC(int n) {
	int &res = dp[n];

	if (res != -1) return res;
	if (n == 1) return 0;

	res = 1000000;

	if (n % 3 == 0) res = min(res,1 + findC(n / 3)); 
	if (n % 2 == 0) res = min(res,1 + findC(n / 2)); 
	res = min(res, 1 + findC(n - 1));
	
	 return res;
}


int main() {

	int N;
	cin >> N;

	memset(dp, -1, sizeof(dp));

	cout << findC(N);

	return 0;
}
