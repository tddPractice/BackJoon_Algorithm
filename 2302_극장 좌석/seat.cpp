/*

2018 Feb 07, made by Moon

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	long dp[42] = { 0, };
	vector<int> v;

	cin >> n;
	cin >> m;

	int tmp = m;
	while (tmp--) {
		int vip;
		cin >> vip;
		v.push_back(vip);
	}

	//프로그램 시작
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (!dp[i]) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	if (m == 0) {
		cout << dp[n] << endl;
		return 0;
	}

	int cnt = 0, res = 1;
	int first, last;
	for (int i = 1; i <= n; i++) {
		if (v.size()) {
			if (i == 1) last = v.back();
			if (i != v.front()) {
				cnt++;
			}
			else {
				res *= dp[cnt];
				cnt = 0;
				first = v.front();
				v.erase(v.begin());
			}
		}
	}
	if (last != n) res *= dp[n - last];

	cout << res << endl;

	return 0;
}
