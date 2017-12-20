/*

2017 Dec 20, made by Jeon

*/

#include <stdio.h>

#define MAX_SIZE 300

int main(void)
{
	int N, M, K, i, j, x, y;
	int arr[MAX_SIZE+1][MAX_SIZE+1] = { 0 };

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1 ; j <= M; j++)
			scanf("%d", &arr[i][j]);

	scanf("%d", &K);
	while(K--)
	{
		scanf("%d %d %d %d", &i, &j, &x, &y);

		int sum = 0;
		for (int col = j; col <= y; col++)
		{
			for (int row = i; row <= x; row++)
			{
				sum += arr[row][col];
			}
		}
		printf("%d\n", sum);
		sum = 0;
	}

	return 0;
}