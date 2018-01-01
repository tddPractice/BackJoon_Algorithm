/*

2017 Dec 28, made by Jeon

*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int main(void)
{
  unsigned long long count;
  string gs;
  vector<int> v;
  int N;
  cin >> N;
  for(int i = 0 ; i <= N ; i++)
  {
    int num;
    cin >> num;
    v.push_back(num);
  }

  count = 1;

  if(N != 1)
  {
    for(int i = 1 ; i < N ; i++)
    {
      if(v[i] == 0)
          count+=2;
      else
      {
        stringstream s;
        count += 3;
        s << v[i];
        gs = s.str();
        count += gs.length();
      }
    }
  }

  if(v[N] != 0)
  {
    stringstream s;
    s << v[N];
    gs = s.str();
    count += 2;
    count += gs.length();
  }
  else
    count++;

  cout << count << endl;
  return 0;
}