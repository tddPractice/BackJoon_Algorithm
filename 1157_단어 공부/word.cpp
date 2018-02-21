/*

2018 Feb 22, made by Moon

*/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	char ch;
	int alpha[26] = { 0 };
	do {
		int k;
		scanf("%c", &ch);
		if (ch == EOF || ch == '\n') {
			break;
		}
		k = ch - 'a' >= 0 ? ch - 'a' : ch - 'A';
		alpha[k]++;
	} while (true);

	priority_queue<pair<int, int> > q;
	for (int i = 0; i <26; i++) {
		q.push(pair<int, int>(alpha[i], i));
	}

	pair<int, int> first = q.top();
	q.pop();
	pair<int, int> second = q.top();

	if (first.first == second.first) {
		printf("?\n");
	}
	else {
		printf("%c\n", first.second + 'A');
	}
	return 0;
}