/*

2017 Dec 28, made by Jeon

*/
#include <iostream>

using namespace std;

int R(int i)
{
  int temp = i;
  int x = 0;
  int j = 1;
  while(1)
  {
    if(i % j == i)
      break;
    j *= 10;
  }

  j /= 10;

  for(int k = 1 ; j > 0 ; k*=10, j /= 10)
  {
    x += (temp/j*k);
    temp -= ((temp/j) * j);
  }

  return x;
}

int main(void)
{
  int N;
  cin >> N;
  while(N--)
  {
    int i , j;
    cin >> i >> j;
    cout << R(R(i) + R(j)) << endl;
  }
  return 0;
}