/*

2018 Feb 12, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data = 0;
	int inDegree = 0;
	vector<int> outDegree;
	bool removed = false;
};
queue<int> q;
int n, m;
vector<node*> v;

void topologicalSort();

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++) {
		node* next = new node;
		next->data = i;
		v.push_back(next);
	}

	int a, b;
	while (m--) {
		scanf("%d %d", &a, &b);
		v[a]->outDegree.push_back(b);
		v[b]->inDegree++;
	}

	topologicalSort();
	printf("\n");
	return 0;
}

void topologicalSort() {
	int flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i < v.size(); i++) {
			if (!v[i]->removed && v[i]->inDegree == 0) {
				printf("%d ", v[i]->data);
				for (int j = 0; j < v[i]->outDegree.size(); j++) {
					v[v[i]->outDegree[j]]->inDegree--;
				}
				v[i]->removed = true;
				flag = true;
			}
		}
	}
}
