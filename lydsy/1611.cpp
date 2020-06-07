/**************************************************************
    Problem: 1611
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:176 ms
    Memory:2932 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
const int Maxn = 310;
const int Maxm = 100010;
int mp[Maxn][Maxn] , inf , n , m , ii , jj , tt , h , t , qx[Maxm] , qy[Maxm] , qt[Maxm];
bool vis[Maxn][Maxn];
const int ss[2][4] = {1 , 0 , -1 , 0 , 0 , 1 , 0 , -1};
 
void bfs() {
    qx[h = 1] = qy[t = 1] = qt[1] = 0;
    while(h <= t) {
        int nx = qx[h] , ny = qy[h] , nowt = qt[h];
        h++;
        if(mp[nx][ny] == inf) {
            printf("%d",nowt);
            return ;
        }
        if(mp[nx][ny] <= nowt) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        for(int i=0; i<4; ++i) {
            int xx = nx + ss[0][i] , yy = ny + ss[1][i];
            if(xx < 0 || yy < 0) continue;
            if(vis[xx][yy]) continue;
            qx[++t] = xx;
            qy[t] = yy;
            qt[t] = nowt+1;
        }
    }
    puts("-1");
}
 
int main() {
    cin>>n;
    memset(mp,42,sizeof(mp));
    inf = mp[0][0];
    for(int i=1; i<=n; ++i) {
        cin>>ii>>jj>>tt;
        mp[ii][jj] = min(mp[ii][jj] , tt);
        for(int j=0; j<4; ++j) {
            int nowi = ii + ss[0][j] , nowj = jj + ss[1][j];
            if(nowi < 0 || nowj < 0) continue;
            mp[nowi][nowj] = min(mp[nowi][nowj] , tt);  
        }
    }
    bfs();
}