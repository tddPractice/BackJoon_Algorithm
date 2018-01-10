/*

2018 Jen 10, made by Jeon

*/

#include <iostream>
#include <cstdio>
using namespace std;

int DFS(int, int, int[1001], int[1001], int[][1001]);

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int soon[1001] = { 0 };
		int map[1001][1001] = { 0 };
		int visited[1001] = { 0 };
		int N, res = 0;

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> soon[i];
		
		for (int i = 1; i <= N; i++)
			map[i][soon[i]] = 1;
		

		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0)
			{
				int last_node = DFS(i, N, soon, visited, map);
				if (soon[last_node] == i)
					res++;
			}
		}

		cout << res << endl;
	}
	return 0;
}

int DFS(int num, int N, int soon[1001], int visited[1001] ,int map[][1001])
{
	int res = num;
	visited[num] = 1;

	for (int i = 1; i <= N ; i++)
		if (map[num][i] == 1 && visited[i] == 0)
			res = DFS(i, N, soon, visited, map);
		
	return res;
}