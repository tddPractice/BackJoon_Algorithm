/*

2018 Mar 5, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 50
using namespace std;

int n;
int v[MAX][MAX], c[MAX][MAX], friends[MAX], visited[MAX];

void bfs(int r) {
	queue<pair<int, int> > q;
	q.push(make_pair(r, 0));
	visited[r] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < n; i++) {
			if (i != r && v[cur][i] == 1) {
				if (cnt + 1== 1) {
                    c[cur][i] = 1;
                    c[i][cur] = 1;
                    c[r][i] = 1;
                    c[i][r] = 1;
					q.push(make_pair(i, cnt + 1));
				}
				else if(cnt + 1== 2){
                    c[cur][i] = 1;
                    c[i][cur] = 1;
                    c[r][i] = 1;
                    c[i][r] = 1;
				}
			}
		}
	}
}

void bfsAll() {
	int visited[MAX];

	for (int i = 0; i < n; i++) {
		fill(visited, visited + MAX, 0);

		bfs(i);
	}

	int maxV = -1;
	for (int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++){
            cnt += c[j][i];
        }
		maxV = maxV < cnt ? cnt : maxV;
	}

	printf("%d\n", maxV);
}

int main() {
	char ch;
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &ch);
			
			if (ch == 'Y') {
				v[i][j] = 1;
			}
			else {
				v[i][j] = 0;
			}
            
            c[i][j] = 0;
		}
		getchar();
	}

	fill(friends, friends + MAX, 0);
	bfsAll();

	return 0;
}