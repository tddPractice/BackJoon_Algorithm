/*

2018 Mar 15, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, m, k;
	int card[101] = { 0 };
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		card[i] = k;
	}

	vector<int> sumTot;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += card[i];
		for (int j = i + 1; j < n; j++) {
			sum += card[j];
			for (int k = j + 1; k < n; k++) {
				sum += card[k];
				if (sum <= m) {
					sumTot.push_back(sum);
				}
				sum -= card[k];
			}
			sum -= card[j];
		}
		sum -= card[i];
	}

	int maxV = 0;
	for (int i = 0; i < sumTot.size(); i++) {
		maxV = maxV > sumTot[i] ? maxV : sumTot[i];
	}

	printf("%d\n", maxV);
	return 0;
}