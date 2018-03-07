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
	vector<int> v; // 연산 횟수의 최소값 저장
	vector<int> pre; // 1로 만드는 과정 중 바로 전 단계 숫자 저장
	cin >> n;

	v.push_back(0); //v[0] = 0
	v.push_back(0); //v[1] = 0
	v.push_back(1); //v[2] = 1
	v.push_back(1); //v[3] = 1

	pre.push_back(0); // pre[0] = 0
	pre.push_back(1); // pre[1] = 1
	pre.push_back(1); // pre[2] = 1
	pre.push_back(1); // pre[3] = 1
	

	for (int i = 4; i <= n; i++)
	{
		int temp = 987654321;
		int prev;
		if (i % 3 == 0)
		{
			temp = v[i / 3] + 1;
			prev = i / 3;
		}
		if (i % 2 == 0)
		{
			int temp2 = temp;
			temp = min(temp, v[i / 2] + 1);
			if (temp2 != temp)
				prev = i / 2;
		}

		int temp2 = temp;
		temp = min(temp, v[i - 1] + 1);
		if (temp2 != temp)
			prev = i - 1;

		v.push_back(temp);
		pre.push_back(prev);
	}

	cout << v[n] << endl;
	for (int i = n; i > 1; i = pre[i])
	{
		cout << i << " ";
	}
	cout << 1 << endl;
	return 0;
}