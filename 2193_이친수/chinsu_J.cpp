/*

2018 Jan 14, made by Jeon

*/
#include <cstdio>

int main(void)
{
  int N;
  long long D[91] = {0};

  scanf("%d", &N);
  D[1] = 1;

  for(int i = 2 ; i <= N ; i++)
    D[i] += D[i-1] + D[i-2];

  printf("%lld\n", D[N]);
  return 0;
}
