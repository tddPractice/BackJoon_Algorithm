/*

2018 Mar 29, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int cnt = 0;
void search(int n, vector<int> &invited, vector<vector<int> > &adj) {
	//find 1-depth
	vector<int> friends;
	for (int i = 0; i < adj[1].size(); i++) {
		friends.push_back(adj[1][i]);
		invited[adj[1][i]] = 1;
		cnt++;
	}

	//search friends friends
	for (int i = 0; i < friends.size(); i++) {
		for (int j = 0; j < adj[friends[i]].size(); j++) {
			if (!invited[adj[friends[i]][j]]) {
				invited[adj[friends[i]][j]] = 1;
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	vector<int> invited(n + 1, 0);
	vector<vector<int> > adj(n + 1, vector<int>());

	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);

		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	invited[1] = 1;
	search(n, invited, adj);
	return 0;
}