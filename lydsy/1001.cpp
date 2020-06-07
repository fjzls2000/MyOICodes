/**************************************************************
    Problem: 1001
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1212 ms
    Memory:102388 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#define inf 1000000001
 
inline int min(register int a , register int b) { return a < b ? a : b ; }
 
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 1000010;
const int Maxm = 6000010;
 
#define R register 
int to[Maxm] , next[Maxm] , g[Maxn] , w[Maxm] , ecnt = 1;
int n , m , S , T , h , t , ans = 0;
int dep[Maxn] , q[Maxm];
 
inline void ins(int a , int b , int c) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = c;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; w[ecnt] = c;
}
 
inline bool bfs() {
    memset(dep,-1,sizeof(dep));dep[T] = 0;
    q[h = t = 1] = T;
    while(h <= t) {
        R int now = q[h++];
        for(R int i=g[now]; i; i=next[i]) {
            if(w[i^1] && dep[to[i]] == -1) {
                dep[to[i]] = dep[now] + 1;
                q[++t] = to[i];
            }
        }
    }
    return dep[S] != -1;
}
 
inline int dfs(int x , int lim) {
    if(x == T) return lim;
    R int v,used = 0;
    for(R int i=g[x]; i; i=next[i]) {
        if(w[i] && (dep[to[i]]+1 == dep[x])) {
            v = dfs(to[i] , min(lim-used , w[i]));
            w[i] -= v;
            w[i^1] += v;
            used += v;
            if(used == lim) return lim;
        }
    }
    if (!used) dep[x]=-1;
    return used;
}
 
void dinic() { while(bfs()) { ans += dfs(S,inf); } }
 
int main() {
    R int tmp;
    n = F(); m = F();
    S = 1 ; T = n*m;
    for(R int i=0; i<n; ++i)
        for(R int j=1; j<m; ++j) {
            tmp = F();
            ins(i*m+j,i*m+j+1,tmp);
        }
    for(R int i=0; i<n-1; ++i)
        for(R int j=1; j<=m; ++j) {
            tmp = F();
            ins(i*m+j,(i+1)*m+j,tmp);
        }
    for(R int i=0; i<n-1; ++i)
        for(R int j=1; j<m; ++j) {
            tmp = F();
            ins(i*m+j,(i+1)*m+j+1,tmp);
        }
    dinic();
    printf("%d\n",ans );
}