/*

2018 May 3, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 52
#define INF 1000000000
using namespace std;

int n, total = 0;
int c[MAX][MAX] = { 0 }, f[MAX][MAX] = { 0 };
vector<int> v[MAX];

//A 65
//Z 90
//a 97
//z 122

int cToi(char ch) {
	if (ch <= 'Z') {
		return ch - 'A';
	}
	return ch - 'a' + 26;
}


void flow() {
	int s = cToi('A'), e = cToi('Z');

	while (true) {
		int prev[MAX];
		queue<int> q;

		fill(prev, prev + MAX, -1);
		
		q.push(s);

		while (!q.empty()) {
			int i = q.front();
			q.pop();

			for (int j : v[i]) {
				if (c[i][j] - f[i][j] > 0 && prev[j] == -1) {
					q.push(j);
					prev[j] = i;

					if (j == e) {
						break;
					}
				}
			}
		}

		if (prev[e] == -1) {
			break;
		}

		int minV = INF;
		for (int i = e; i != s; i = prev[i]) {
			minV = min(minV, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = e; i != s; i = prev[i]) {
			f[prev[i]][i] += minV;
			f[i][prev[i]] -= minV;
		}

		total += minV;

		queue<int>().swap(q);
	}

	printf("%d\n", total);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char s, e;
		int w;
		scanf(" %c %c %d", &s, &e, &w);

		s = cToi(s);
		e = cToi(e);

		c[s][e] += w;
		c[e][s] += w;
		v[s].push_back(e);
		//역방향 간선도 추가해야함
		v[e].push_back(s);
	}

	flow();

	return 0;
}