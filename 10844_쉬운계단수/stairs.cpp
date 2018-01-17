/*

2018 Jan 17, made by Jeon

*/
#include <cstdio>
int main(void)
{
 long long gds[101][10] = { 0 };
 long long res = 0;
 int N;
 scanf("%d", &N);
 for (int i = 1; i <= 9; i++)
  gds[1][i] = 1;
 for (int i = 2; i <= N; i++)
 {
  gds[i][0] = gds[i - 1][1];
  gds[i][1] = gds[i - 1][2] + gds[i - 1][0];
  gds[i][2] = gds[i - 1][3] + gds[i - 1][1];
  gds[i][3] = gds[i - 1][4] + gds[i - 1][2];
  gds[i][4] = gds[i - 1][5] + gds[i - 1][3];
  gds[i][5] = gds[i - 1][6] + gds[i - 1][4];
  gds[i][6] = gds[i - 1][7] + gds[i - 1][5];
  gds[i][7] = gds[i - 1][8] + gds[i - 1][6];
  gds[i][8] = gds[i - 1][9] + gds[i - 1][7];
  gds[i][9] = gds[i - 1][8];
  for (int j = 0; j <= 9; j++)
   gds[i][j] %= 1000000000;
 }
 for (int i = 0; i <= 9; i++)
 {
  res += gds[N][i];
  res %= 1000000000;
 }
 printf("%lld\n", res);
 return 0;
} 