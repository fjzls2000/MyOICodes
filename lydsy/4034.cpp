/**************************************************************
    Problem: 4034
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:3636 ms
    Memory:17156 kb
****************************************************************/
 
#include <stdio.h>
inline int max(const int&a , const int&b) { return a > b ? a : b ; }
inline int min(const int&a , const int&b) { return a < b ? a : b ; }
inline void swap(int&a , int&b) { register int c = a; a=b; b = c; }
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
const int Maxm = Maxn<<1;
const int Maxt = Maxn<<2;
int n , m , a[Maxn] , size[Maxn] , ed[Maxn] , son[Maxn] , dep[Maxn] , s[Maxn] , fa[Maxn] , bl[Maxn] , pl[Maxn] , dfn = 0 , to[Maxm] , next[Maxm] , g[Maxn] , ecnt = 0 , ll[Maxt] , rr[Maxt];
long long tree[Maxt] , lazy[Maxt];
inline void ins(const int&a , const int&b) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt;
}
void dfs1(int x) {
    size[x] = 1; dep[x] = dep[fa[x]] + 1;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        dfs1(to[i]);
        size[x] += size[to[i]];
        if(size[to[i]] > size[son[x]]) son[x] = to[i];
    }
}
void dfs2(int x , int y) {
    bl[x] = y; ed[x] = pl[x] = ++dfn;
    if(!son[x]) return;
    dfs2(son[x] , y);
    ed[x] = max(ed[x] , ed[son[x]]);
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x] || to[i] == son[x]) continue;
        dfs2(to[i],to[i]);
        ed[x] = max(ed[x] , ed[to[i]]);
    }
}
inline void downpush(const int&x) {
    if(ll[x] == rr[x]) return;
    if(lazy[x]) {
        tree[x<<1] += lazy[x] * (rr[x<<1] - ll[x<<1] + 1);
        tree[x<<1|1] += lazy[x] * (rr[x<<1|1] - ll[x<<1|1] + 1);
        lazy[x<<1] += lazy[x];
        lazy[x<<1|1] += lazy[x];
        lazy[x] = 0;
    }
}
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid); Build(x<<1|1 , mid+1 , r);
}
long long query(int x , int l , int r) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return 0;
    if(l == ll[x] && r == rr[x]) return tree[x];
    return query(x<<1 , l , r) + query(x<<1|1 , l , r);
}
void modify(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) {
        tree[x] += (long long) val * (rr[x] - ll[x] + 1);
        lazy[x] += val;
        return;
    }
    modify(x<<1 , l , r , val) , modify(x<<1|1 , l , r , val);
    tree[x] = tree[x<<1] + tree[x<<1|1];
}
int main() {
    n = F() , m = F();
    for(int i=1; i<=n; ++i)
        a[i] = F();
    for(int i=1; i<n; ++i)
        ins(F(),F());
    dfs1(1);
    dfs2(1,1);
    Build(1,1,n);
    for(int i=1; i<=n; ++i) modify(1,pl[i],pl[i],a[i]);
    while(m--) {
        int op = F();
        if(op == 1) {
            int x = F() , val = F();
            modify(1,pl[x],pl[x],val);
        }else if(op == 2) {
            int x = F() , val = F();
            modify(1,pl[x],ed[x],val);
        }else {
            int x = F(); long long ans = 0;
            while(x) {
                ans += query(1,pl[bl[x]],pl[x]);
                x = fa[bl[x]];
            } printf("%lld\n",ans);
        }
    }
}