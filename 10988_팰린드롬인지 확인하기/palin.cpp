/*

2018 Feb 25, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	char ch;
	int n = 0;
	vector<char> v;
	while (scanf("%c", &ch) != EOF && ch != '\n' && ch != '\0') {
		v.push_back(ch);
		n++;
	}

	int front = 0;
	int rear = n - 1;
	int isPalin = 1;

	while (front <= rear) {
		if (v[front] != v[rear]) {
			isPalin = 0;
			break;
		}
		front++;
		rear--;
	}
	printf("%d\n", isPalin);
	return 0;
}