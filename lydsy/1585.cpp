/**************************************************************
    Problem: 1585
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:112 ms
    Memory:7952 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#define inf 233333333
 
inline int min(int a , int b) { return a < b ? a : b ; }
 
const int Maxn = 100010;
const int Maxm = 400010;
int n , m , k , ecnt = 1 , to[Maxm] , next[Maxm] , g[Maxn] , flow[Maxm] , dep[Maxn] , q[Maxm] , S , T , h , t , ans = 0;
bool vis[Maxn];
 
inline void ins(int a , int b , int c) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; flow[ecnt] = c;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; flow[ecnt] = 0;
}
 
void init() {
    scanf("%d%d%d",&n,&m,&k);
    S = n+n+1; T = S + 1;
    ins(S,1,inf);
    for(int i=1; i<=m; ++i) {
        int a , b;
        scanf("%d%d",&a,&b);
        ins(a+n,b,inf);
        ins(b+n,a,inf);
    } 
    for(int i=1; i<=k; ++i) {
        int a;
        scanf("%d",&a);
        vis[a] = 1;
        ins(a+n,T,inf);
    }
    for(int i=1; i<=n; ++i) {
        if(i == 1 || vis[i]) ins(i,i+n,inf);
        else ins(i,i+n,1);
    }
}
 
bool bfs() {
    memset(dep,-1,sizeof(dep)); dep[T] = 0;
    q[h = t = 1] = T;
    while(h <= t) {
        int now = q[h++];
        for(int i=g[now]; i; i=next[i]) {
            if(dep[to[i]] == -1 && flow[i^1]) {
                dep[to[i]] = dep[now] + 1;
                q[++t] = to[i];
            }
        }
    }
    return dep[S] != -1;
}
 
int dfs(int x , int lim) {
    if(x == T) return lim;
    int used = 0 , v;
    for(int i=g[x]; i; i=next[i]) {
        if(flow[i] && dep[to[i]] == dep[x] - 1) {
            v = dfs(to[i] , min(lim-used , flow[i]));
            flow[i] -= v;
            flow[i^1] += v;
            used += v;
            if(used == lim) return used;
        }
    }
    if(!used) dep[x] = -1;
    return used;
}
 
void dinic() { while(bfs()) ans+=dfs(S,inf); }
 
int main() {
    init();
    dinic();
    printf("%d",ans);
}