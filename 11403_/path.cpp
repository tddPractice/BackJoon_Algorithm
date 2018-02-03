/*

2018 Feb 02, made by Moon

*/
#include <iostream>

using namespace std;

int N;
int graph[101][101];
int result[101][101];
int visited[101];

void dfs(int head, int root) {
	visited[root]++;
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && graph[root][i]) {
			result[head][i] = 1;
			dfs(head, i);
		}
	}
}

void dfsAll() {
	for (int i = 1; i <= N; i++) {
		visited[i] = -1;
		dfs(i, i);
        for(int j=1; j<=N; j++){
            visited[j] = 0;
        }
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}


	dfsAll();
	//출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
