/*

2018 Mar 19, made by Moon

*/
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

bool isUniqNum(int n) {
	for (int i = 2; i <= n - 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void check(int a, int b) {
	if (a == b) {
		printf("0\n");
		return;
	}

	int cnt = 0;
	map<int, int> m;
	queue<int> q;
	q.push(a);

	while (!q.empty()) {
		int n, convertedN, prevConvertedN;
		int size = q.size();
		int isDone = 0;

		for (int s = 0; s < size; s++) {
			char ch[4], ch2[4];
			n = q.front();
			prevConvertedN = n;

			if (n == b) {
				isDone = 1;
				break;
			}
			m[n] = 1;
			q.pop();

			ch[0] = (n / 1000) + '0';
			n %= 1000;
			ch[1] = (n / 100) + '0';
			n %= 100;
			ch[2] = (n / 10) + '0';
			n %= 10;
			ch[3] = n + '0';

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					ch2[0] = ch[0];
					ch2[1] = ch[1];
					ch2[2] = ch[2];
					ch2[3] = ch[3];

					if (i == 0) {
						if (j != 0) {
							ch2[i] = j + '0';
						}
					}
					else {
						ch2[i] = j + '0';
					}

					convertedN = (ch2[0] - '0') * 1000 + (ch2[1] - '0') * 100 + (ch2[2] - '0') * 10 + (ch2[3] - '0');
					
					if (m[convertedN] == 0 && isUniqNum(convertedN)) {
						q.push(convertedN);
						m[convertedN] = 1;
					}
				}
			}
		}
		if (isDone) {
			break;
		}
		cnt++;
	}
	printf("%d\n", cnt);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);

		check(a, b);
	}
	return 0;
}