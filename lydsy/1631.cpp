/**************************************************************
    Problem: 1631
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:4436 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#include <queue>
 
inline int max(int a , int b) { return a > b ? a : b ; }
 
const int Maxn = 100010;
const int Maxm = 200010;
struct E {
    int u , v , w;
} a[Maxn];
 
struct node {
    int x , dist;
};
bool operator < (node a , node b) {
    return a.dist > b.dist;
}
 
int n , m , x , to[Maxn] , next[Maxn] , g[Maxn] , w[Maxn] , dis[Maxn] , ecnt = 0 , dis2[Maxn];
bool vis[Maxn];
 
void ins(int a , int b , int wi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi;
}
 
std::priority_queue<node> q;
 
void dj() {
    node tmp;
    tmp.x = x;
    tmp.dist = 0;
    memset(dis,42,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top(); q.pop();
        int now = tmp.x , dist = tmp.dist;
        if(vis[now]) continue;
        vis[now] = 1;
        dis[now] = dist;
        for(int i=g[now]; i; i=next[i]) {
            if(!vis[to[i]]) {
                tmp.x = to[i];
                tmp.dist = dist + w[i];
                q.push(tmp);
            }
        }
    }
}
 
int main() {
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1; i<=m; ++i)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w) , ins(a[i].u,a[i].v,a[i].w);
    dj();
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        dis2[i] = dis[i];
    }
    memset(g,0,sizeof(g));
    ecnt = 0;
    for(int i=1; i<=m; ++i)
        ins(a[i].v,a[i].u,a[i].w);
    dj();
    for(int i=1; i<=n; ++i) {
        ans = max(ans , dis[i]+dis2[i]);
    }
    printf("%d",ans);
}