//코인1

#include <stdio.h>

int main(void)
{
	int n, k;
	int D[10001] = { 0 };
	int Coin[101] = { 0 };

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		scanf("%d", &Coin[i]);


	for (int i = 1; i <= n; i++)
	{
		if (Coin[i] <= 10000)
		{
			D[Coin[i]]++;
			for (int j = 1; j <= k; j++)
			{
				if (j - Coin[i] > 0)
					D[j] += D[j - Coin[i]];
			}
		}
	}

	printf("%d\n", D[k]);
	return 0;
}