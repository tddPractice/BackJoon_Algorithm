/*

2018 Jan 23, made by Jeon

*/
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

long long ACM(vector<int>, vector<int>*, vector<int>, int, int);

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int N, K, W;
        scanf("%d %d", &N, &K); // N : 건물개수 ,  K : 규칙개수

        vector<int> ct; // construction time
        vector<int> graph[N+1]; // u -> v 저장
        vector<int> degree;
        degree.resize(N+1);

        for(int i = 0 ; i < N ; i++)
        {
            int time;
            scanf("%d", &time);
            ct.push_back(time);
        }

        while(K--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            degree[v]++;
        }

        scanf("%d", &W);

        printf("%lld\n", ACM(ct, graph, degree, N, W));
    }
    return 0;
}

long long ACM(vector<int> ct, vector<int> *graph, vector<int> degree, int N, int W)
{
    /*  진입차수가 0인애들로부터 시작해서
        인접한 노드들의 진입차수를 -1시키면서 건축시간 갱신
    */
    vector<long long> res; // return res[W]
    queue<int> zeroDegree;
    res.resize(N+1);

    for(int i = 1 ; i <= N ; i++) //초기화 ,, W가 처음부터 진입차수가 0인애들 중 하나일수도..
        res[i] = (long long)ct[i-1];

    for(int i = 1 ; i <= N ; i++)
        if(!degree[i])
            zeroDegree.push(i);

    while(!zeroDegree.empty())
    {
        int cur = zeroDegree.front();
        zeroDegree.pop();
        if(cur == W)
	return res[W];

        int len = graph[cur].size();
        for(int i = 0 ; i < len ; i++)
        {
            int next = graph[cur][i];
            res[next] = max(res[next], res[cur] + (long long)ct[next-1]);
            degree[next]--;
            if(!degree[next])
            {
                zeroDegree.push(next);
                if(next == W)
                    return res[W];
            }
        }
    }

    return res[W];
}