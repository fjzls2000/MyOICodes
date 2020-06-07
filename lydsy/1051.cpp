/**************************************************************
    Problem: 1051
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:72 ms
    Memory:5252 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
using std::min;using std::max;
const int Maxn = 50001;
const int Maxm = 200010;
 
int n , m , a[Maxn] , dfn[Maxn] , low[Maxn] , belong[Maxn] , q[Maxn] , top = 0;
int to[Maxm] , next[Maxm] , g[Maxm] , h[Maxm] , ecnt = 0 , nodecnt = 0 , dfncnt = 0;
bool vis[Maxn] , inq[Maxn];
 
void Insg(int a , int b) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
}
void Insh(int a , int b) {
    to[++ecnt] = b;
    next[ecnt] = h[a];
    h[a] = ecnt;
}
 
void Init() {
    int f,t;
    scanf("%d%d",&n,&m);
    while(m--) {
        scanf("%d%d",&f,&t);
        Insg(f,t);
    }
}
 
void dfs(int x) {
    int now = 0;
    dfn[x] = low[x] = ++dfncnt;
    vis[x] = inq[x] = 1;
    q[++top] = x;
    for(int i = g[x]; i; i=next[i])
        if(!vis[to[i]]) {
            dfs(to[i]);
            low[x] = min(low[x] , low[to[i]]);
        }else if(inq[to[i]]) low[x] = min(low[x] , dfn[to[i]]);
    if( dfn[x] == low[x] ) {
        nodecnt++;
        while(now!=x) {
            now = q[top--];
            inq[now] = 0;
            belong[now] = nodecnt;
            a[nodecnt]++;
        }
    }
}
 
void rebuild() {
    for(int i=1; i<=n; i++)
        for(int j=g[i]; j; j=next[j])
            if(belong[i] != belong[to[j]])
                Insh(belong[i] , belong[to[j]]);
}
 
void tarjan() {
    for(int i=1; i<=n; i++) if(!vis[to[i]]) dfs(i);
    rebuild();
}
 
int Solve() {
    int ans = 0;
    for(int i=1; i<=nodecnt; i++)
        if(h[i] == 0) if(ans) return 0;
        else ans = i;
    return a[ans];
}
 
int main() {
    Init();
    tarjan();
    printf("%d",Solve());
}