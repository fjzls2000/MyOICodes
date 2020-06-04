/**************************************************************
    Problem: 2243
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:9480 ms
    Memory:38472 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using std::min; using std::max; using std::swap;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 400001;
const int Maxm = 400001;
const int Maxt = 819201;
#define R register
int n , m , bl[Maxn] , pos[Maxn] , size[Maxn] , dep[Maxn] , v[Maxn] , fa[Maxn] , son[Maxn] , dfn = 0;
int to[Maxm] , next[Maxm] , g[Maxn] , ecnt = 0;
int ll[Maxt] , rr[Maxt] , sum[Maxt] , lazy[Maxt] , lcol[Maxt] , rcol[Maxt];
inline void ins(int a , int b) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; }
void dfs1(int x) {
    size[x] = 1; dep[x] = dep[fa[x]] + 1;
    for(R int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        dfs1(to[i]);
        size[x] += size[to[i]];
        if(size[to[i]] > size[son[x]]) son[x] = to[i];
    }
}
void dfs2(int x , int y) {
    bl[x] = y; pos[x] = ++dfn;
    if(!son[x]) return;
    dfs2(son[x],y);
    for(R int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x] || to[i] == son[x]) continue;
        dfs2(to[i],to[i]);
    }
}
int lca(int a , int b) {
    while(bl[a] != bl[b]) {
        if(dep[bl[a]] < dep[bl[b]]) swap(a,b);
        a = fa[bl[a]];
    }return dep[a] <= dep[b] ? a : b ;
}
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r; sum[x] = 1; lazy[x] = -1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid); Build(x<<1|1 , mid+1 , r);
}
void update(int x) {
    lcol[x] = lcol[x<<1]; rcol[x] = rcol[x<<1|1];
    if(rcol[x<<1] ^ lcol[x<<1|1]) sum[x] = sum[x<<1] + sum[x<<1|1];
    else sum[x] = sum[x<<1] + sum[x<<1|1] - 1;
}
void downpush(int x) {
    int tmp = lazy[x]; lazy[x] = -1;
    if(ll[x] == rr[x] || tmp == -1) return;
    sum[x<<1] = sum[x<<1|1] = 1;
    lazy[x<<1] = lazy[x<<1|1] = tmp;
    lcol[x<<1] = lcol[x<<1|1] = tmp;
    rcol[x<<1] = rcol[x<<1|1] = tmp;
}
void modify(int x , int l , int r , int val) {
    downpush(x);
    l = max(l , ll[x]); r = min(r , rr[x]);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) { sum[x] = 1; lcol[x] = rcol[x] = lazy[x] = val; return; }
    else { modify(x<<1 , l , r , val); modify(x<<1|1 , l , r , val); update(x); }
}
int query(int x , int l , int r) {
    downpush(x);
    l = max(l , ll[x]); r = min(r , rr[x]);
    if(l == ll[x] && r == rr[x]) return sum[x];
    if(r < ll[x<<1|1]) return query(x<<1 , l , r);
    else if(l > rr[x<<1]) return query(x<<1|1 , l , r);
    else {
        int tmp = 1;
        if(rcol[x<<1] ^ lcol[x<<1|1]) tmp = 0;
        return query(x<<1 , l , r) + query(x<<1|1 , l , r) - tmp;
    }
}
int getcol(int x , int k) {
    downpush(x);
    if(ll[x] == rr[x]) return lcol[x];
    int mid = (ll[x] + rr[x]) >> 1;
    if(k <= mid) return getcol(x<<1 , k);
    else return getcol(x<<1|1 , k);
}
int getsum(int x , int f) {
    int ans = 0;
    while(bl[x] != bl[f]) {
        ans += query(1,pos[bl[x]],pos[x]);
        if(getcol(1,pos[fa[bl[x]]]) == getcol(1,pos[bl[x]])) --ans;
        x = fa[bl[x]];
    }ans += query(1,pos[f],pos[x]);
    return ans;
}
void change(int x , int f , int val) {
    while(bl[x] != bl[f]) {
        modify(1,pos[bl[x]],pos[x],val);
        x = fa[bl[x]];
    }modify(1,pos[f],pos[x],val);
}
void init() {
    n = F() , m = F();
    for(R int i=1; i<=n; ++i)
        v[i] = F();
    for(R int i=1 , a , b; i<n; ++i) {
        a = F() , b = F();
        ins(a,b) , ins(b,a);
    }
}
char op[10];
void solve() {
    dfs1(1);
    dfs2(1,1);
    Build(1,1,n);
    for(int i=1; i<=n; ++i)
        modify(1,pos[i],pos[i],v[i]);
    while(m--) {
        scanf("%s",op);
        if(op[0] == 'Q') {
            R int a = F() , b = F();
            R int L = lca(a,b);
            printf("%d\n",getsum(a,L)+getsum(b,L)-1);
        }
        else {
            R int a = F() , b = F() , val = F();
            R int L = lca(a,b);
            change(a,L,val); change(b,L,val);
        }
    }
}
int main() {
    init();
    solve();
}