/*

2017 Dec 20, made by Jeon

*/

#include <stdio.h>
#define MAX 1001

int main(void)
{
	int n, max = 0;
	int A[MAX] = { 0 };
	int D[MAX] = { 0 };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		D[i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		int temp = 0;
		for (int x = i - 1; x >= 1; x--)
		{
			if (A[i] > A[x])
			{
				temp = D[x] + 1;
				if (D[i] < temp)
					D[i] = temp;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (max < D[i])
			max = D[i];

	printf("%d\n", max);
	return 0;
}