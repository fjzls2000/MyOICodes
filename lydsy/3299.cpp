/**************************************************************
    Problem: 3299
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:32 ms
    Memory:87912 kb
****************************************************************/
 
#include <stdio.h>
const int ss[2][4] = {0,0,1,-1 , 1,-1,0,0};
const int Maxn = 1010;
char s[Maxn]; bool vis[Maxn][Maxn];
int map[Maxn][Maxn] , id[Maxn][Maxn] , d[26][2] , q[10000010] , qt[10000010];
int main() {
    int n , m , idcnt = 0 , bingo , h , t;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) {
        scanf("%s",s+1);
        for(int j=1; j<=m; ++j) {
            id[i][j] = ++idcnt;
            if(s[j] != '#') map[i][j] = 1; else map[i][j] = 0;;
            if(s[j] == '@') q[h = t = 1] = id[i][j] , vis[i][j] = 1;;
            if(s[j] == '=') bingo = id[i][j];
            if(s[j]>='A' && s[j]<='Z') {
                map[i][j] = s[j]-'A'+2;
                if(!d[s[j]-'A'][0]) d[s[j]-'A'][0] = id[i][j];
                else d[s[j]-'A'][1] = id[i][j];
            }
        }
    }
    //bfs
    while(h<=t) {
        int nowt = qt[h] , now = q[h++];
        if(now == bingo) return !printf("%d",nowt);
        int x = (now-1)/m , y = now-x*m; ++x;
         
        for(int i=0; i<4; ++i) {
            int tx = x + ss[0][i] , ty = y + ss[1][i] , nxt;
            if(vis[tx][ty] || !map[tx][ty] || tx<1 || ty<1 || tx>n || ty>m) continue;
            vis[tx][ty] = 1;
            if(map[tx][ty] > 1) {
                int tmp = map[tx][ty] - 2;
                if(id[tx][ty] == d[tmp][0]) nxt = d[tmp][1];
                else nxt = d[tmp][0];
            }else nxt = id[tx][ty];
            q[++t] = nxt; qt[t] = nowt+1;
        }
    }
} 