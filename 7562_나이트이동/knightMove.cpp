/*

2018 Jan 14, made by Jeon

*/
#include <cstdio>
#include <queue>

using namespace std;

const int y_dir[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int x_dir[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int Knight(int,int[],int[]);

struct pos{
  int y;
  int x;
};

int main(void)
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int L;
    int cur_pos[2] = {0};
    int tar_pos[2] = {0};

    scanf("%d", &L);
    scanf("%d %d", &cur_pos[0], &cur_pos[1]);
    scanf("%d %d", &tar_pos[0], &tar_pos[1]);

    printf("%d\n", Knight(L, cur_pos, tar_pos));
  }
  return 0;
}

int Knight(int L, int cur_pos[], int tar_pos[])
{
    int visited[301][301] = {0};
    int move_cnt = 0;
    int ca = 0; // current area
    queue<pos> q;
    pos p = {cur_pos[0], cur_pos[1]};
    q.push(p);

    while(q.size())
    {
      ca = q.size();
      for(int k = 0 ; k < ca ; k++)
      {
        pos p = q.front();
        q.pop();

        if(p.y == tar_pos[0] && p.x == tar_pos[1])
          return move_cnt;

        for(int i = 0 ; i < 8 ; i++)
        {
          if(p.y + y_dir[i] >= 0 && p.y + y_dir[i] < L &&
          p.x + x_dir[i] >= 0 && p.x + x_dir[i] < L)
          {
            if(visited[p.y + y_dir[i]][p.x + x_dir[i]] == 0)
            {
              pos next = { p.y + y_dir[i], p.x + x_dir[i] };
              q.push(next);
              visited[p.y + y_dir[i]][p.x + x_dir[i]] = 1;
            }
          }
        }
      }

      move_cnt++;
    }

    return move_cnt;
}