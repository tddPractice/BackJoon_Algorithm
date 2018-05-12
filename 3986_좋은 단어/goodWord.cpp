/*

2018 May 13, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 100001
using namespace std;

bool check() {
	char ch[MAX];
	scanf("%s", ch);

	vector<char> st;

	int size = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		size++;
	}

	if (size % 2 == 1) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (st.size() > 0) {
			if (st.back() == ch[i]) {
				st.pop_back();
			}
			else {
				st.push_back(ch[i]);
			}
		}
		else {
			st.push_back(ch[i]);
		}
	}
	
	if (st.size() > 0) {
		return false;
	}

	return true;
}

int main() {
	int n, cnt;
	scanf("%d", &n);

	cnt = 0;
	while (n--) {
		if (check()) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}