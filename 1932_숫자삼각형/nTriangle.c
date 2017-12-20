/*

2017 Dec 20, made by Jeon

*/

#include <stdio.h>
#define MAX 501
#define BIG(A,B) A>B?A:B

int main(void)
{
	int n, max = -1;
	int D[MAX][MAX] = { 0 };
	int input[MAX][MAX] = { 0 };

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &input[i][j]);

	for (int i = 0; i <= n; i++)
	{
		D[i][0] = -1;
		D[0][i] = -1;
	}

	D[1][1] = input[1][1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			D[i][j] = BIG(D[i - 1][j - 1] + input[i][j], D[i - 1][j] + input[i][j]);
		
	for (int i = 1; i <= n; i++)
		if (max < D[n][i])
			max = D[n][i];
	printf("%d\n", max);
	return 0;
}