/*

2018 Mar 19, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

char ch[1000002];
int main() {
	vector<char> v;
	vector<int> res;

	scanf("%s", ch);
	for (int i = 0; ch[i] != '\0'; i++) {
		v.push_back(ch[i]);
	}

	for (int i = v.size() - 1, j = 1; i >= 0; i -= 3, j *= 10) {
		int pow = 0;
		
		if (v[i] == '1') {
			pow += 1;
		}
		if (i - 1 >= 0) {
			if (v[i - 1] == '1') {
				pow += 2;
			}
		}
		if (i - 2 >= 0) {
			if (v[i - 2] == '1') {
				pow += 4;
			}
		}
		res.push_back(pow);
	}
	
	for (int i = res.size() - 1; i >= 0; i--) {
		if (res.size() > 1 && i == res.size() - 1) {
			if (res[i] != 0) {
				printf("%d", res[i]);
			}
		}else {
			printf("%d", res[i]);
		}
	}
	printf("\n");
	return 0;
}