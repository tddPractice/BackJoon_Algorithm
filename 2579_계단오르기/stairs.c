/*

2017 Dec 19, made by Jeon

*/

#include <stdio.h>
#define MAX_STAIRS 301
#define MAX(A,B) A>B?A:B

int main(void)
{
   int n;
   int S[MAX_STAIRS] = { 0 };
   int D[MAX_STAIRS] = { 0 };

   scanf("%d", &n);
   for (int i = 1; i <= n; i++)
      scanf("%d", &S[i]);

   D[1] = S[1];
   for (int i = 2; i <= n; i++)
   {
      if (i < 3)
      {
         D[i] = D[i - 1] + S[i];
      }
      else
      {
         D[i] = MAX(D[i - 3] + S[i-1] + S[i], D[i - 2] + S[i]);
      }
   }

   printf("%d\n", D[n]);
   return 0;
}
