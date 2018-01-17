/*

2018 Jan 17, made by Inho

*/
#include <cstdio>
int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N;
		long long P[101] = { 0 };
		scanf("%d", &N);

		P[1] = P[2] = P[3] = 1;
		P[4] = 2;
		for (int i = 5; i <= N; i++)
		{
			P[i] = P[i - 5] + P[i - 1];
		}
		printf("%lld\n", P[N]);
	}

	return 0;
}