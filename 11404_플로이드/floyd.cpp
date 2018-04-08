/*

2018 Apr 8, made by Moon

*/
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

int main(void)
{
    int n, m, adj[101][101] = {0};
    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++)
            if(i != j)
                adj[i][j] = INF;

    while(m--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = min(adj[u][v] , w);
    }

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1; j <= n ; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1 ; j <= n; j++)
            printf("%d ", adj[i][j]);
        puts("");
    }
    return 0;
}
