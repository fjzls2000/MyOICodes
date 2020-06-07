/**************************************************************
    Problem: 1934
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:20340 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define INF 214748364
using std::min; using std::max;
const int Maxn = 410;
const int Maxm = 1000010;
int n , to[Maxm] , next[Maxm] , g[Maxm] , flow[Maxm] , q[Maxm] , ans = 0 , ecnt = 1 , S , T;
void Ins(int a , int b , int c) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    flow[ecnt] = c;
    g[a] = ecnt;
    /*================*/
    to[++ecnt] = a;
    next[ecnt] = g[b];
    flow[ecnt] = 0;
    g[b] = ecnt;
}
void Ins2(int a , int b , int c) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    flow[ecnt] = c;
    g[a] = ecnt;
    /*================*/
    to[++ecnt] = a;
    next[ecnt] = g[b];
    flow[ecnt] = c;
    g[b] = ecnt;
}
int o[Maxn];
bool bfs() {
    int i , head , h , t;
    q[h = t = 0] = S;
    memset(o,-1,sizeof(o));
    while(h<=t) {
        head = q[h++]; i = g[head];
        while(i) {
            if(flow[i] && o[to[i]] < 0) {
                o[to[i]] = o[head] + 1;
                q[++t] = to[i];
            }i=next[i];
        }
    }if(o[T] == -1) return 0;
    return 1;
}
int dfs(int x, int f) {
    if(x == T) return f;
    int w , used = 0;
    for(int i = g[x]; i; i=next[i]) {
        if(flow[i] && o[to[i]] == o[x] + 1) {
            w = dfs(to[i] , min( f - used , flow[i] ) ); 
            flow[i] -= w;
            flow[i^1] += w;
            used+=w;
            if(used == f) return f;
        }
    }if(!used) o[x] = -1;
    return used;
}
void dinic() {while(bfs())ans+=dfs(S,INF);}
int main() {
    int a , b , m;
    /*Init*/
    scanf("%d%d",&n,&m);
     S = n + 1 ; T = S + 1;
    for(int i=1; i<=n; i++) {
        scanf("%d",&a);
        if( a == 1 ) Ins(S , i , 1);
        else Ins(i,T,1);
    }
    while(m--) {
        scanf("%d%d",&a,&b);
        Ins2(a,b,1);
    }
    /*Solve*/
    dinic();
    /*End*/
    printf("%d",ans);
    return 0;
}