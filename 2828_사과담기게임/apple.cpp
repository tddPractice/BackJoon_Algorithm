/*

2018 Jen 01, made by Jeon

*/

#include <iostream>
using namespace std;

int main(void)
{
  int n, j, m;
  int move_len = 0;
  int apples[20] = {0};
  cin >> n >> m >> j;

  int posL = 1, posR = m;

  for(int i = 0 ; i < j ; i++)
    cin >> apples[i];

  for(int i = 0 ; i < j ; i++)
  {
    if(apples[i] < posL)
    {
      int len = posL - apples[i];
      move_len += len;
      posL -= len;
      posR -= len;
    }
    else if(apples[i] > posR)
    {
      int len = apples[i] - posR;
      move_len += len;
      posL += len;
      posR += len;
    }
  }

  cout << move_len << endl;

  return 0;
}


