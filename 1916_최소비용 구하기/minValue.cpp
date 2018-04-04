/*

2018 Apr 4, made by Moon

*/
#include <cstdio>
#include <queue>
#include <vector>
#define INF 150000000
using namespace std;

struct node {
	int v = 0;
	int w = 0;
};

void djikstra(int n, int s, int e, vector<int> &dist, vector<vector<node*> > &adj) {
	priority_queue<pair<int, int> > q;

	q.push(make_pair(0, s));
	dist[s] = 0;

	while (!q.empty()) {
		pair<int, int> p = q.top();
		int size = adj[p.second].size();
		vector<node*> node = adj[p.second];
		q.pop();

		p.first = -p.first;

		for (int i = 0; i < size; i++) {
			if (dist[node[i]->v] > node[i]->w + p.first) {
				dist[node[i]->v] = node[i]->w + p.first;
				q.push(make_pair(-dist[node[i]->v], node[i]->v));
			}
		}
	}

	printf("%d\n", dist[e]);
}

int main() {
	int n, m, s, e;
	scanf("%d %d", &n, &m);

	vector<vector<node*> > v(n + 1, vector<node*>());
	vector<int> dist(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);

		node* newNode = new node;
		newNode->v = to;
		newNode->w = weight;

		v[from].push_back(newNode);
	}
	scanf("%d %d", &s, &e);

	djikstra(n, s, e, dist, v);
	return 0;
}