/**************************************************************
    Problem: 1295
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:380 ms
    Memory:1624 kb
****************************************************************/
 
#include <stdio.h>
#include <math.h>
#include <memory.h>
inline int F() {register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
struct node { int x , y; } q[100010];
double ans = 0;
int n , m , T , mp[31][31] , dis[31][31] , h , t , inq[31][31];
char str[40];
const int ss[2][4] = {1,0,-1,0 , 0,1,0,-1};
void getans(int x , int y) {
    for(int i=x; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(dis[i][j] <= T && (y-j)*(y-j)+(x-i)*(x-i) > ans)
                ans = (y-j)*(y-j)+(x-i)*(x-i);
}
void search(int xx , int yy) {
    h = t = 1;
    q[1].x = xx; q[1].y = yy;
    memset(inq,0,sizeof(inq));
    memset(dis,42,sizeof(dis));
    dis[xx][yy] = mp[xx][yy]; inq[xx][yy] = 1;
    while(h <= t) {
        int nowx = q[h].x , nowy = q[h].y; ++h;
        for(int i=0; i<4; ++i) {
            int nx = nowx + ss[0][i] , ny = nowy + ss[1][i];
            if(nx > n || nx < xx || ny > m || ny < 1) continue;
            if (dis[nx][ny] > dis[nowx][nowy] + mp[nx][ny]) {
                dis[nx][ny] = dis[nowx][nowy] + mp[nx][ny];
                if(!inq[nx][ny]) {
                    q[++t].x = nx; q[t].y = ny; inq[nx][ny] = 1;
                }
            }
        }
        inq[nowx][nowy] = 0;
    }
    getans(xx,yy);
}
int main() {
    n = F(); m = F(); T = F();
    for(int i=1; i<=n; ++i) {
        scanf("%s",str);
        for(int j=0; j<m; ++j)
            mp[i][j+1] = str[j]-'0';
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            search(i,j);
    printf("%.6lf",sqrt(ans));
}