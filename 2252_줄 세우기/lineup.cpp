/*

2018 Jan 21, made by Jeon

*/
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;
    queue<int> sq;
    queue<int> rq;
    vector<int> degree;
    vector<vector<int> > heights;

    scanf("%d %d", &N, &M);

    heights.resize(N+1);
    degree.resize(N+1);

    while(M--)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        heights[start].push_back(end);
        degree[end]++;
    }

    for(int i = 1; i <= N; i++)
    {
        if(degree[i] == 0)
            sq.push(i);
    }

    while(!sq.empty())
    {
        int cur = sq.front();
        sq.pop();
        rq.push(cur);

        int len = heights[cur].size();
        for(int i = 0 ; i < len; i++)
        {
            degree[heights[cur][i]]--;
            if(degree[heights[cur][i]] == 0)
                sq.push(heights[cur][i]);
        }
    }

    int len = rq.size();
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d ", rq.front());
        rq.pop();
    }
    printf("\n");
    return 0;
}