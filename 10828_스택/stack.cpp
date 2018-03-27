/*

2018 Mar 27, made by Moon

*/
#include <cstdio>
#include <stack>
using namespace std;

int getPow(int n, int cnt) {
	int k = 1;
	for (int i = 1; i < cnt; i++) {
		k *= 10;
	}
	return k * n;
}

int getStackNum(char ch[20]) {
	int size = 0, num = 0;
	for (int i = 5; ch[i] != '\n'; i++) {
		size++;
	}
	for (int i = 5, j = size; i < size + 5; i++, j--) {
		num += getPow((ch[i] - '0'), j);
	}
	return num;
}

int main() {
	int n;
	stack<int> st;
	scanf("%d", &n);
	getchar();

	while (n--) {
		int i = 0;
		char c;
		char ch[20];

		while (true) {
			scanf("%c", &c);
			ch[i++] = c;
			if (!(c != '\n' && c != EOF && c != '\0')) {
				break;
			}
		}

		switch (ch[0]) {
		case 'p':
			if (ch[1] == 'u') {
				st.push(getStackNum(ch));
			}
			else if (ch[1] == 'o') {
				if (st.empty()) {
					printf("-1\n");
				}
				else {
					printf("%d\n", st.top());
					st.pop();
				}
			}
			break;
		case 's':
			printf("%d\n", st.size());
			break;
		case 'e':
			if (st.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
			break;
		case 't':
			if (st.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", st.top());
			}
			break;
		default:
			break;
		}
	}
	return 0;
}