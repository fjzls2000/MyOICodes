/**************************************************************
    Problem: 1050
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:3592 ms
    Memory:1956 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
using std::max ; using std::min;
const int Maxn = 5001;
const int Maxm = 50001;
int n , m , u , v ;
int dis[Maxn] , vis[Maxn] , a[Maxm];
int to[Maxm] , next[Maxm] , g[Maxm] , W[Maxm] , ecnt = 0;
 
struct E {int i , dist;};
bool operator < (E a , E b) { return a.dist > b.dist ;}
std::priority_queue<E> q;
 
int gcd(int a , int b) {
    if(b == 0) return a;
    else return gcd(b,a%b);
}
 
int ansx = 100000001, ansy = 1;
void cmp(int a , int b) {
    long long tmp1 = a , tmp2 = b;
    tmp1 *= ansy; tmp2 *= ansx;
    if(tmp1 < tmp2) {
        ansx = a;ansy = b;
        int tmp = gcd(ansx,ansy);
        ansx/=tmp;
        ansy/=tmp;
    }
}
 
void Ins(int a , int b , int wi) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    W[ecnt] = wi;
    g[a] = ecnt;
}
 
void unique() {
    int cnt = 1;
    for(int i=2; i<=m; i++)
        if(a[i] != a[cnt]) a[++cnt] = a[i];
    m = cnt;
}
 
bool dijk(int Min) {
    while(!q.empty()) q.pop();
    memset(dis,42,sizeof(dis));
    memset(vis,0,sizeof(vis));
    const int INF = dis[0];
    int dist , head;
    q.push((E){u,0});
    while(!q.empty() && !vis[v]) {
        head = q.top().i;
        dist = q.top().dist;
        q.pop();
        if(vis[head]) continue;
        vis[head] = 1;
        dis[head] = dist;
        for(int i=g[head]; i; i=next[i])
            if(W[i] >= Min)
                q.push((E){to[i],max(W[i] , dist)});
    }cmp(dis[v],Min);
    return dis[v] < INF;
}
 
int main() {
    int f , t , wi;
    scanf("%d%d",&n,&m);
    for(int i = 1; i<=m; i++) {
        scanf("%d%d%d",&f,&t,&wi);
        Ins(f,t,wi);
        Ins(t,f,wi);
        a[i] = wi;
    }
    scanf("%d%d",&u,&v);
    std::sort(a+1,a+m+1);
    unique();
    if(!dijk(a[1])) {
        puts("IMPOSSIBLE");
        return 0;
    }
    for(int i=2; i<=m; i++) {
        dijk(a[i]);
    }
    if(ansy > 1) printf("%d/%d",ansx,ansy);
    else printf("%d",ansx);
}