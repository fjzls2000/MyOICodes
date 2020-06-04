/**************************************************************
    Problem: 1070
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:428 ms
    Memory:6788 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#include <memory.h>
using std::min; using std::max;
#define inf 233333333
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0' || ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0' && ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int n , m , v[61][61] , to[100001] , next[100001] , g[1001] , w[100001] , flow[100001] , ecnt = 1 , cost = 0 , S , T , fr[1001] , q[1000001] , dis[1001]; bool inq[1001];
void ins(int a , int b , int wi , int flowi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi; flow[ecnt] = flowi;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; w[ecnt] = -wi; flow[ecnt] = 0;
}
void init() {
    n = F() , m = F();
    S = 601; T = 602;
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            v[i][j] = F();
    for(int i=1; i<=n*m; ++i)
        ins(S,i,0,1);
    for(int i=1; i<=m; ++i)
        ins(n*m+i,T,0,1);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            for(int k=1; k<=m; ++k)
                ins((i-1)*m+j,n*m+k,v[k][i]*j,1);
}
bool spfa() {
    int h = 1 , t = 1;
    memset(dis,42,sizeof(dis)); dis[S] = 0;
    memset(fr,0,sizeof(fr));
    q[1] = S; inq[S] = 1;
    while(h <= t) {
        int now = q[h++];
        for(int i=g[now]; i; i=next[i])
            if(flow[i] && dis[to[i]] > dis[now] + w[i]) {
                dis[to[i]] = dis[now] + w[i]; fr[to[i]] = i;
                if(!inq[to[i]]) { inq[to[i]] = 1; q[++t] = to[i]; }
            }
        inq[now] = 0;
    } return fr[T];
}
void mcf() {
    while(spfa()) {
        int mn = inf;
        for(int i = fr[T]; i; i=fr[to[i^1]])
            mn = min(mn , flow[i]);
        for(int i = fr[T]; i; i=fr[to[i^1]])
            flow[i^1] += mn , flow[i] -= mn;
        cost += dis[T]*mn;
    }
}
int main() {
    init();
    mcf();
    printf("%.2lf",(double)cost/m);
}