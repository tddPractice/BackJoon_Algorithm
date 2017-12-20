/*

2017 Dec 20, made by Jeon

*/

RGB거리 

#include <stdio.h>
#define N 1001
#define MIN(A,B) A>B?B:A

int main(void)
{
	int n, temp;
	int R[N] = { 0 };
	int G[N] = { 0 };
	int B[N] = { 0 };
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		int cr, cg, cb;
		scanf("%d %d %d", &cr, &cg, &cb);

		R[i] = MIN(G[i - 1] + cr, B[i - 1] + cr);
		G[i] = MIN(R[i - 1] + cg, B[i - 1] + cg);
		B[i] = MIN(R[i - 1] + cb, G[i - 1] + cb);
	}

	temp = MIN(R[n], G[n]);
	printf("%d\n", MIN(temp, B[n]));

	return 0;
}