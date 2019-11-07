/**************************************************************
    Problem: 1984
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:7908 ms
    Memory:15272 kb
****************************************************************/
 
#include <stdio.h>
inline int max(const int&a , const int&b) { return a > b ? a : b ; }
inline int min(const int&a , const int&b) { return a < b ? a : b ; }
inline void swap(int&a , int&b) { register int c = a; a = b; b = c; }
inline int F() { register int aa , bb ,ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
const int Maxm = 200010;
const int Maxt = 409610;
int n , dep[Maxn] , fa[Maxn] , son[Maxn] , size[Maxn] , pl[Maxn] , bl[Maxn] , v[Maxn] , dfn = 0;
int to[Maxm] , next[Maxm] , g[Maxn] , w[Maxm] , ecnt = 0; bool vis[Maxm];
int ll[Maxt] , rr[Maxt] , tree[Maxt] , lazy[Maxt] , tag[Maxt];
inline void ins(int a , int b , int wi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; w[ecnt] = wi;
}
void dfs1(int x) {
    dep[x] = dep[fa[x]] + 1; size[x] = 1;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        v[to[i]] = w[i]; vis[i] = 1;
        dfs1(to[i]);
        size[x] += size[to[i]];
        if(size[to[i]] > size[son[x]]) son[x] = to[i];
    }
}
void dfs2(int x , int y) {
    bl[x] = y; pl[x] = ++dfn;
    if(!son[x]) return;
    dfs2(son[x],y);
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x] || to[i] == son[x]) continue;
        dfs2(to[i] , to[i]);
    }
}
int lca(int a , int b) {
    while(bl[a] != bl[b]) {
        if(dep[fa[bl[a]]] < dep[fa[bl[b]]]) swap(a,b);
        a = fa[bl[a]];
    } return dep[a] < dep[b] ? a : b;
}
void update(int x) {  tree[x] = max(tree[x<<1] , tree[x<<1|1]); }
void downpush(int x) {
    if(ll[x] == rr[x]) { lazy[x] = 0; tag[x] = -1; return; }
    if(tag[x] != -1) {
        lazy[x<<1] = lazy[x<<1|1] = 0;
        tag[x<<1] = tag[x<<1|1] = tag[x];
        tree[x<<1] = tree[x<<1|1] = tag[x];
        tag[x] = -1;
    }
    if(lazy[x]) {
        tree[x<<1] += lazy[x];
        tree[x<<1|1] += lazy[x];
        if(tag[x<<1] == -1) lazy[x<<1] += lazy[x];
        else tag[x<<1] += lazy[x];
        if(tag[x<<1|1] == -1) lazy[x<<1|1] += lazy[x];
        else tag[x<<1|1] += lazy[x];
        lazy[x] = 0;
    }
}
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r; tag[x] = -1; lazy[x] = tree[x] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid); Build(x<<1|1 , mid+1 , r);
}
int query(int x , int l , int r) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return 0;
    if(l == ll[x] && r == rr[x]) return tree[x];
    return max(query(x<<1 , l , r) , query(x<<1|1 , l , r));
}
void modifyadd(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) {
        lazy[x] += val;
        tree[x] += val;
        return;
    }
    else {
        modifyadd(x<<1 , l , r , val);
        modifyadd(x<<1|1 , l , r , val);
        update(x);
    }
}
void modifytag(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) {
        tag[x] = tree[x] = val;
        lazy[x] = 0;
        return;
    }
    else {
        modifytag(x<<1 , l , r , val);
        modifytag(x<<1|1 , l , r , val);
        update(x);
    }
}
void solmodify(int x , int f , int val) {
    while(bl[x] != bl[f]) {
        modifytag(1,pl[bl[x]],pl[x],val);
        x = fa[bl[x]];
    }if(pl[f]+1 <= pl[x]) modifytag(1,pl[f]+1,pl[x],val);
}
int solquery(int x , int f) {
    int ans = 0;
    while(bl[x] != bl[f]) {
        ans = max(ans , query(1,pl[bl[x]],pl[x]));
        x = fa[bl[x]];
    }if(pl[f]+1 <= pl[x]) ans = max(ans , query(1,pl[f]+1,pl[x]));
    return ans;
}
void soladd(int x , int f , int val) {
    while(bl[x] != bl[f]) {
        modifyadd(1,pl[bl[x]],pl[x],val);
        x = fa[bl[x]];
    }if(pl[f]+1 <= pl[x]) modifyadd(1,pl[f]+1,pl[x],val);
}
char op[10];
int main() {
    n = F();
    for(int i=1; i<n; ++i) {
        int a = F() , b = F() , wi = F();
        ins(a,b,wi);
    }
    dfs1(1);
    dfs2(1,1);
    Build(1,1,n);
    for(int i=1; i<=n; ++i)
        modifytag(1,pl[i],pl[i],v[i]);
    while(scanf("%s",op)) {
        if(op[0] == 'C') {
            if(op[1] == 'h') {
                int k = F() , val = F();
                if(vis[k<<1]) k = to[k<<1];
                else k = to[(k<<1)-1];
                modifytag(1,pl[k],pl[k],val);
            }
            else{
                int a = F() , b = F() , val = F();
                int L = lca(a , b);
                solmodify(a,L,val); solmodify(b,L,val);
            }
        }
        else if(op[0] == 'M') {
            int a = F() , b = F();
            int L = lca(a , b);
            printf("%d\n",max(solquery(a,L),solquery(b,L)) );
        }
        else if(op[0] == 'A') {
            int a = F() , b = F() , val = F();
            int L = lca(a,b);
            soladd(a,L,val); soladd(b,L,val);
        }else break;
    }
}