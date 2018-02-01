/*

2018 Feb 01, made by Moon

*/ 

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void fib(int n) {
	vector<pair<int, int>> v;
	int first, second;

	v.push_back(pair<int, int>(1, 0)); // fib(0)
	v.push_back(pair<int, int>(0, 1)); // fib(1)

	for (int ix = 2; ix <= n; ix++) {
		if (v.size() < ix + 1) {
			// 해당 인덱스에 대한 메모이제이션이 수행되지 않음
			first = v[ix - 1].first + v[ix - 2].first;
			second = v[ix - 1].second + v[ix - 2].second;
			v.push_back(pair<int, int>(first, second));
		}
	}

	cout << v[n].first << " " << v[n].second << endl;
}

int main()
{
	int N;
	int t;
	vector<int> arr;

	cin >> N;
	for (int ix = 0; ix < N; ix++) {
		cin >> t;
		arr.push_back(t);
	}

	for (int ix = 0; ix < N; ix++) {
		fib(arr[ix]);
	}

	return 0;
}


