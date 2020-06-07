/**************************************************************
    Problem: 1003
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:64 ms
    Memory:2904 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
const int Maxn = 110;
const int Maxm = 100010; 
inline long long min(register long long a , register long long b) { return a < b ? a : b ; }
 
int T , n , m , k , to[Maxm] , next[Maxm] , g[Maxm] , W[Maxm] , ecnt = 0 , D[Maxn][Maxn] , del[Maxn] , inq[Maxn] , q[Maxm] , h , t , dis[Maxn];
long long  f[Maxn] , s[Maxn][Maxn];
inline void ins( register int a , register int b , register int wi) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; W[ecnt] = wi; }
 
inline int spfa(int a , int b) {
    memset(del,0,sizeof(del));
    memset(inq,0,sizeof(inq));
    memset(dis,42,sizeof(dis));
    for(int i=a; i<=b; ++i)
        for(int j=1; j<=n; ++j)
            if(D[i][j]) del[j] = 1;
    q[h = t = 1] = 1; dis[1] = 0; inq[1] = 1;
    while(h<=t) {
        int now = q[h++];
        for(int i=g[now]; i; i=next[i])
            if(!del[to[i]] && dis[to[i]] > dis[now] + W[i]) {
                dis[to[i]] = dis[now] + W[i];
                if(!inq[to[i]]) {inq[to[i]] = 1; q[++t] = to[i];}
            }
        inq[now] = 0;
    }return dis[n];
}
 
int main() {
    int a , b , vi , ci;
    scanf("%d%d%d%d",&T,&n,&k,&m);
    for(int i=1; i<=m; ++i) {
        scanf("%d%d%d",&a,&b,&vi);
        ins(a , b , vi);
        ins(b , a , vi);
    }
    scanf("%d",&ci);
    while(ci--) {
        scanf("%d%d%d",&vi,&a,&b);
        for(int i=a; i<=b; ++i) D[i][vi] = 1;
    }
    for(int i=1; i<=T; ++i)
        for(int j=i; j<=T; ++j)
            s[i][j] = spfa(i , j);
/*  for(int i=1; i<=T; ++i) {
        for(int j=1; j<=T; ++j)
            printf("%d\t",s[i][j]);
        puts("");
    }*/
    for(int i=1; i<=T; ++i) f[i] = (long long)s[1][i]*i;
    for(int i=2; i<=T; ++i)
        for(int j=1; j<i; ++j)
            f[i] = min(f[i] , f[j]+s[j+1][i]*(i-j)+k);
    printf("%lld",f[T]);
}