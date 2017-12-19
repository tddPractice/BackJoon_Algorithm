/*

2017 Dec 19, made by Jeon

*/


#include <stdio.h>
#define MAX_GLASSES 10001
#define MAX(A,B) A>B?A:B
int main(void)
{
	int n;
	int G[MAX_GLASSES] = { 0 };
	int D[MAX_GLASSES] = { 0 };
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &G[i]);

	D[1] = G[1];
	for (int i = 2; i <= n; i++)
	{
		if (i < 3)
		{
			D[i] = D[i - 1] + G[i];
		}
		else
		{
			int temp = MAX(D[i - 3] + G[i - 1] + G[i], D[i - 1]);
			D[i] = MAX(D[i - 2] + G[i], temp);			
		}
	}

	printf("%d\n", D[n]);
	return 0;
}