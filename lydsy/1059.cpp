/**************************************************************
    Problem: 1059
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:328 ms
    Memory:896 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
const int Maxn = 301; 
bool map[Maxn][Maxn] , vis[Maxn] ;int used[Maxn] , n;
bool find(int x) {
    for(int i=1; i<=n; ++i)
        if(!vis[i] && map[x][i]) {
            vis[i] = 1;
            if(!used[i] || find(used[i])) {
                used[i] = x;
                return 1;
            }
        }
    return 0;
}
int main() {
    int t , ch;
    scanf("%d",&t);
    while(t--) {
        memset(used,0,sizeof(used));
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d",&map[i][j]);
        for(int i=1; i<=n; ++i) {
            memset(vis,0,sizeof(vis));
            if(!find(i)) {puts("No"); goto END;}
        }puts("Yes");END: 1;
    }
}