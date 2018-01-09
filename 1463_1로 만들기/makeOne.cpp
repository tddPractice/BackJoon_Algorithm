/*

2018 Jen 09, made by Jeon

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	vector<int> v;

	cin >> n;

	v.push_back(0); //v[0]
	v.push_back(0); //v[1]
	v.push_back(1); //v[2]
	v.push_back(1); //v[3]

	for (int i = 4; i <= n; i++)
	{
		int temp = 987654321;
		if (i % 3 == 0)
		{
			temp = v[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			temp = min(temp, v[i / 2] + 1);
		}
		temp = min(temp, v[i - 1] + 1);
		v.push_back(temp);
	}

	cout << v[n] << endl;
	return 0;
}