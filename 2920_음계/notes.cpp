/*

2018 Mar 15, made by Moon

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int arr[8];
	int k;

	int prevInt;
	char result = 'y';
	for (int i = 0; i < 8; i++) {
		scanf("%d", &k);
		arr[i] = k;
	}

	for (int i = 0; i < 8; i++) {
		if (i == 0) {
			prevInt = arr[i];
		}
		else {
			if (abs(prevInt - arr[i]) > 1) {
				printf("mixed\n");
				return 0;
			}
			else {
				prevInt = arr[i];
			}
		}
	}

	if (arr[0] == 1 && arr[7] == 8) {
		printf("ascending\n");
	}
	else if (arr[0] == 8 && arr[7] == 1) {
		printf("descending\n");
	}
	else {
		printf("mixed\n");
	}
	return 0;
}