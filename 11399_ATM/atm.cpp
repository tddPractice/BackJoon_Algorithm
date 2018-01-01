/*

2017 Dec 28, made by Jeon

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  int N, sum = 0;
  cin >> N;

  vector<int> v;
  while(N--)
  {
    int pi;
    cin >> pi;
    v.push_back(pi);
  }

  sort(v.begin(), v.end());

  int len = v.size();
  int temp = 0;
  for(int i = 0 ; i < len ; i++)
  {
    temp += v[i];
    sum += temp;
  }
  
  cout << sum << endl;
  return 0;
}