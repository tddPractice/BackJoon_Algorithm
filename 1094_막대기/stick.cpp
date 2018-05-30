/*

2018 May 30, made by Moon

*/
#include <cstdio>
#include <vector>

using namespace std;

int x, cnt;
vector<int> v;

void start() {
	while (true) {
		int sum = 0;

		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}

		if (sum > x) {
			int tmp = v.back() / 2;

			sum = 0;
			for (int j = 0; j < v.size() - 1; j++) {
				sum += v[j];
			}
			sum += tmp;

			if (sum > x) {
				v.back() = tmp;
			}
			else if (sum == x) {
				printf("%d\n", v.size());
				return;
			}
			else {
				v.back() = tmp;
				v.push_back(tmp);
			}
		}
		else if (sum == x) {
			printf("%d\n", v.size());
			return;
		}
	}
}

int main() {
	scanf("%d", &x);

	v.push_back(64);

	cnt = 0;
	start();
	

	return 0;
}