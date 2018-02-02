/*

2018 Feb 02, made by Moon

*/ 
#include <iostream>
#include <vector>
using namespace std;

int T;
int N;

void dfs(int root, int graph[][1001], int node[1001], int visited[1001]) {
	visited[root] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[root][i] == 1 && !visited[i]) {
			dfs(i, graph, node, visited);
		}
	}
}

void dfsAll(int graph[][1001], int node[1001], int visited[1001]) {
	int dfsN = 0;

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfsN++;
			dfs(i, graph, node, visited);
		}
	}
	cout << dfsN << endl;
}

int main() {
	cin >> T;


	for (int i = 0; i < T; i++) {
		cin >> N;

		int node[1001] = { 0 };
		int visited[1001] = { 0 };
		int graph[1001][1001] = { 0 };



		for (int j = 1; j <= N; j++) {
			cin >> node[i];
			graph[j][node[i]] = 1;
		}
		dfsAll(graph, node, visited);
	}
}
