/**************************************************************
    Problem: 1576
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4008 ms
    Memory:34016 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int inf = 233333333;
#define getch() getchar()
inline int F() {
    register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200010;
const int Maxm = 800020;
int n , m , to[Maxm] , next[Maxm] , g[Maxn] , ecnt , w[Maxm] , dis[Maxn] , from[Maxn] , size[Maxn] , fa[Maxn] , dep[Maxn] , son[Maxn] , bl[Maxn] , pl[Maxn] , tcnt = 0 , ll[Maxm] , rr[Maxm] , tree[Maxm] , lazy[Maxm];
bool vis[Maxn] , mark[Maxm];
void ins(int a , int b , int wi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; w[ecnt] = wi;
}
 
struct node {
    int x , dist;
};
bool operator < (node a , node b) {
    return a.dist > b.dist;
}
 
struct Edge{
    int u , v , w;
} e[Maxn];
 
void downpush(int x) {
    if(ll[x] == rr[x] || lazy[x] == inf) return;
    tree[x<<1] = min(tree[x<<1] , lazy[x]);
    lazy[x<<1] = min(lazy[x<<1] , lazy[x]);
    tree[x<<1|1] = min(tree[x<<1|1] , lazy[x]);
    lazy[x<<1|1] = min(lazy[x<<1|1] , lazy[x]);
    lazy[x] = inf;
}
 
void dijk() {
    priority_queue<node> q;
    while(!q.empty()) q.pop();
    for(int i=2; i<=n; ++i) dis[i] = inf;
    dis[1] = 0;
    node tmp;
    tmp.x = 1;tmp.dist = 0;
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();q.pop();
        int now = tmp.x , dist = tmp.dist;
        if(vis[now])continue;
        vis[now] = 1;
        for(int i=g[now]; i; i=next[i])
            if (dis[to[i]] > dis[now]+w[i]) {
                dis[to[i]] = dis[now]+w[i];
                mark[from[to[i]]] = 0;
                from[to[i]] = i;
                mark[i] = 1;
                tmp.x = to[i];
                tmp.dist =  dis[to[i]];
                q.push(tmp);
            }
    }
}
 
void dfs1(int x) {
    size[x] = 1;
    for(int i=g[x]; i; i=next[i]) {
        if(!mark[i]) continue;
        fa[to[i]] = x;
        dep[to[i]] = dep[x] + 1;
        dfs1(to[i]);
        size[x] += size[to[i]];
        if(size[to[i]] > size[son[x]]) son[x] = to[i];
    }
}
void dfs2(int x , int y) {
    bl[x] = y; pl[x] = ++tcnt;
    if(!son[x]) return;
    dfs2(son[x],y);
    for(int i=g[x]; i; i=next[i]) {
        if(!mark[i] || to[i] == fa[x] || to[i] == son[x]) continue;
        dfs2(to[i],to[i]);
    }
}
 
int lca(int x , int y) {
    while(bl[x] != bl[y]) {
        if(dep[bl[x]] < dep[bl[y]]) swap(x,y);
        x = fa[bl[x]];
    }
    return dep[x] > dep[y] ? y : x ;
}
 
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r;
    tree[x] = lazy[x] = inf;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid);
    Build(x<<1|1 , mid+1 , r);
}
 
void modify(int x , int l , int r , int v) {
    downpush(x);
    l = max(l , ll[x]); r = min(r , rr[x]);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) {
        lazy[x] = min(lazy[x],v);
        if(l == r) tree[x] = min(tree[x],v);
        return;
    }
    int mid = (l + r) >> 1;
    modify(x<<1 , l , r , v);
    modify(x<<1|1 , l , r , v);
}
 
void solve(int x , int f , int val) {
    while(bl[x] != bl[f]) {
        modify(1,pl[bl[x]],pl[x],val);
        x = fa[bl[x]];
    }
    if(x != f) modify(1,pl[f]+1,pl[x],val);
}
 
int query(int x , int k) {
    downpush(x);
    if(ll[x] == rr[x]) return tree[x];
    if(rr[x<<1] >= k) return query(x<<1,k);
    else return query(x<<1|1 , k);
}
 
int main() {
    n = F(); m = F();
    for(int i=1; i<=m; ++i) {
        e[i].u = F(); e[i].v = F(); e[i].w = F();
        ins(e[i].u,e[i].v,e[i].w);
    }
    dijk();
    dfs1(1);
    dfs2(1,1);
    Build(1,1,n);
    for(int i=1; i<=m; ++i) {
        int f = lca(e[i].u , e[i].v);
        if(!mark[2*i-1]) solve(e[i].v,f,dis[e[i].u]+dis[e[i].v]+e[i].w);
        if(!mark[2*i]) solve(e[i].u,f,dis[e[i].u]+dis[e[i].v]+e[i].w);
    }
    for(int i=2; i<=n; ++i) {
        int t = query(1,pl[i]);
        if(t == inf) puts("-1");
        else printf("%d\n",t-dis[i]);
    }
}