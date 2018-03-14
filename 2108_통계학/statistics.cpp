/*

2018 Mar 14, made by Moon

*/
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	vector<int> v;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		v.push_back(k);
	}

	// 산술평균
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	printf("%.0f\n", sum / n);

	// 중앙 값
	sort(v.begin(), v.end());
	printf("%d\n", v[n / 2]);

	// 최빈값
	int maxV = -9999, maxCnt = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (!m[v[i]]) {
			m[v[i]] = 1;
		}
		else {
			m[v[i]]++;
		}
	}

	for (int i = 0; i < n; i++) {
		maxV = max(maxV, m[v[i]]);
	}

	vector<int> list;
	for (int i = 0; i < n; i++) {
		if (m[v[i]] == maxV) {
			list.push_back(v[i]);
		}
	}

	sort(list.begin(), list.end());
	maxV = list[0];
	for (int i = 0; i < list.size(); i++) {
		if (maxV < list[i]) {
			maxV = list[i];
			break;
		}
	}
	printf("%d\n", maxV);

	// 범위
	printf("%d\n", v.back() - v.front());
	return 0;
}