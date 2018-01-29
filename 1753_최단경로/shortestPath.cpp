/*

2018 Jan 23, made by Jeon

*/
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define INF 987654321

using namespace std;

vector<int> dijkstra(int,int,vector<pair<int, int> >*);

int main(void)
{
    int V, E, K;
    vector<pair<int, int> > graph[20001];

    scanf("%d %d %d", &V, &E, &K);

    for(int i = 0 ; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }

    vector<int> res = dijkstra(V, K, graph);

    int len = res.size();
    for(int i = 1 ; i < len ; i++)
    {
        if(res[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",res[i]);
    }
    return 0;
}

vector<int> dijkstra(int V, int K, vector<pair<int, int> >* graph)
{
    vector<int> dist;
    vector<int> visited;
    dist.resize(V+1, INF);
    visited.resize(V+1);
    priority_queue<pair<int, int> > pq; // w , v 순으로 저장

    dist[K] = 0;
    pq.push(make_pair(0, K));

    while(!pq.empty())
    {
        //방문하지 않은 노드 중, dist가 가장 작은 노드로 이동
        pair<int, int> p = pq.top();
        pq.pop();
        int cur = p.second;

        visited[cur] = 1;

        //인접한 노드들의 dist를 갱신

        int len = graph[cur].size();

        for(int i = 0 ; i < len ; i++)
        {
            int next = graph[cur][i].first; // 다음 노드
            int next_dist = graph[cur][i].second; // 가중치
            if(!visited[next] && dist[next] > dist[cur] + next_dist)
            {
                dist[next] = dist[cur] + next_dist;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    return dist;
}