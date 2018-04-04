/*

2018 Apr 3, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct vertex {
	int data = 0;
	int weight = 0;
	vertex* next = NULL;
};

struct node {
	int data = 0;
	vertex* next = NULL;
	vertex* last = NULL;
};

void djikstra(int n, int s, vector<node*> &vec, vector<int> &dist) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, s));
	dist[s] = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			pair<int, int> v = q.top();
			q.pop();

			v.first = -v.first;

			vertex* tmp = vec[v.second]->next;

			while (vec[v.second]->next != NULL) {
				if (dist[vec[v.second]->next->data] > v.first + vec[v.second]->next->weight) {
					dist[vec[v.second]->next->data] = v.first + vec[v.second]->next->weight;
					
					q.push(make_pair(-dist[vec[v.second]->next->data], vec[v.second]->next->data));
				}
				vec[v.second]->next = vec[v.second]->next->next;
			}

			vec[v.second]->next = tmp;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
}

int main() {
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);

	vector<node*> vec;
	vector<int> dist(n + 1, INF);

	for (int i = 0; i <= n; i++) {
		node* newNode = new node;
		vec.push_back(newNode);
	}

	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		if (vec[u]->data == 0) {
			vec[u]->data = u;
		}

		vertex* ver = new vertex;
		ver->data = v;
		ver->weight = w;

		if (vec[u]->last == NULL) {
			vec[u]->next = ver;
			vec[u]->last = vec[u]->next;
		}
		else {
			vec[u]->last->next = ver;
			vec[u]->last = ver;
		}
	}

	djikstra(n, s, vec, dist);
	return 0;
}
