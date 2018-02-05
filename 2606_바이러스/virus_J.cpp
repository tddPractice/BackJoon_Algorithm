/*

made by Jeon

*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int C, T;
int total = 0;
int net[101][101] = {0};
int virus[101] = {0};

void infection(int com)
{
  for(int i = 1 ; i <= C ; i++)
  {
    if(net[com][i] == 1 && virus[i] == 0)
    {
      virus[com] = 1;
      v.push_back(i);
      total++;
    }
  }

  if(v.size() == 0)
    return;

  int temp = v.front();
  v.erase(v.begin());
  infection(temp);
}

int main(void)
{
  cin >> C >> T;

  while(T--)
  {
    int i, j;
    cin >> i >> j;
    net[i][j] = 1;
    net[j][i] = 1;
  }

  virus[1] = 1;
  infection(1);

  cout << total << endl;

  return 0;
}
