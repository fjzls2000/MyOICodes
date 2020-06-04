/**************************************************************
    Problem: 2252
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1940 ms
    Memory:12620 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
const int Maxn = 1010;
struct node { int x , y; } q[1000001] ;
int dis[Maxn][Maxn] , h , t , n , m , ch;
const int sx[4] = {1,0,-1,0}; const int sy[4] = {0,1,0,-1};
int main() {
    h = t = 0;
    memset(dis,42,sizeof(dis));
    const int inf = dis[0][0];
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            while(ch = getchar() , ch != '0' && ch != '1');
            if(ch == '1') {
                q[++t].x = i;
                q[t].y = j;
                dis[i][j] = 0;
            }
        }
    while(h != t) {
        node now = q[++h]; if(h == 1000000) h = 0;
        for(int i=0; i<4; ++i) {
            int nx = now.x+sx[i] , ny = now.y+sy[i];
            if(nx > n || ny > m || nx < 1 || ny < 1) continue;
            if(dis[nx][ny] == inf) {
                dis[nx][ny] = dis[now.x][now.y]+1;
                q[++t].x=nx; q[t].y = ny;
                if(t == 1000000) t = 1;
            }
        }
    }
    for(int i=1; i<=n; puts(""),++i)
        for(int j=1; j<=m; ++j)
            printf("%d ",dis[i][j]);
}