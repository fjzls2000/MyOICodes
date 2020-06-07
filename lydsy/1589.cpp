/**************************************************************
    Problem: 1589
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:336 ms
    Memory:10532 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 600010;
int n , to[Maxn] , f[Maxn] , ru[Maxn];
bool vis[Maxn];
void kill(int x) {
    --ru[to[x]];
    vis[x] = 1;
    if(!ru[to[x]]) kill(to[x]);
}
int dfs1(int x) {
    if(vis[x]) return f[x];
    vis[x] = 1;
    return (f[x] = dfs1(to[x]) +1);
}
void dfs2(int x , int y) {
    if(f[x] == 1) {
        f[x] = y;
        return;
    }
    f[x] = y;
    dfs2(to[x],y);
}
int dfs3(int x) {
    if(f[x]) return f[x];
    return (f[x] = dfs3(to[x]) +1);
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&to[i]) , ++ru[to[i]];
    for(int i=1; i<=n; ++i) {
        if(!vis[i] && !ru[i]) kill(i);
    }
    for(int i=1; i<=n; ++i) {
        if(!vis[i]) dfs2(i,dfs1(i));
    }
    for(int i=1; i<=n; ++i) {
        printf("%d\n",dfs3(i));
    }
}