/*

2018 Jen 09, made by Jeon

*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int x_dir[4] = { 0,1,0,-1 };
const int y_dir[4] = { 1,0,-1,0 };

int visited[27][27] = { 0 };
int map[27][27] = { 0 };

struct pos {
	int y;
	int x;
};

int bfs(int, int);

int main(void)
{
	int N;
	vector<int> v;
	cin >> N;	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);
		
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				int res = bfs(i, j);
				v.push_back(res);
			}
		}
	}

	sort(v.begin(), v.end());
	int size = v.size();

	cout << size << endl;
	for (int i = 0; i < size; i++)
		cout << v[i] << endl;

	return 0;
}

int bfs(int y, int x)
{
	int res = 1;
	queue<pos> qp;
	pos p;
	p.y = y;
	p.x = x;
	
	qp.push(p);
	visited[p.y][p.x] = 1;

	while (qp.size())
	{
		p = qp.front();
		qp.pop();
		for (int z = 0; z < 4; z++)
		{
			if (map[p.y + y_dir[z]][p.x + x_dir[z]] == 1 &&
				visited[p.y + y_dir[z]][p.x + x_dir[z]] == 0)
			{
				pos temp;
				temp.y = p.y + y_dir[z];
				temp.x = p.x + x_dir[z];
				qp.push(temp);
				visited[temp.y][temp.x] = 1;
				res++;
			}
		}
	}
	return res;
}