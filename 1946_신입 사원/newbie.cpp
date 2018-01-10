/*

2018 Jan 10, made by Jeon

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct score {
	int x; // 서류
	int y; // 면접
};

bool operator <(const score &a, const score &b) {
	return a.x < b.x;
}


int main(void)
{
	int T, N;
	cin >> T;
	while (T--)
	{
		vector<score> v;
		cin >> N;
		int temp = N;
		int res = N;
		while (temp--)
		{
			score s;
			cin >> s.x >> s.y;
			v.push_back(s);
		}

		sort(v.begin(), v.end());
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{	
				if (v[j].y < v[i].y)
				{
					res--;
					break;
				}
			}
		}
		cout << res << endl;
	}

	return 0;
}