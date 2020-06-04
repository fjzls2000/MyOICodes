/**************************************************************
    Problem: 1577
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:548 ms
    Memory:8248 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define inf 233333333
 
inline int max(register int a , register int b) { return a > b ? a : b ; }
inline int min(register int a , register int b) { return a < b ? a : b ; }
 
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 100010;
const int Maxt = 400010;
struct cow { int l , r , w; } q[Maxn];
bool operator < (cow a , cow b) { return a.r == b.r ? a.l > b.l : a.r < b.r ; }
#define R register
int n , m , lim , ans , ll[Maxt] , rr[Maxt] , tr[Maxt] , lazy[Maxt];
 
void downpush(int x) {
    if(ll[x] == rr[x]) return;
    if(lazy[x]) {
        tr[x<<1] += lazy[x];
        lazy[x<<1] += lazy[x];
        tr[x<<1|1] += lazy[x];
        lazy[x<<1|1] += lazy[x];
        lazy[x] = 0;
    }
}
 
void update(int x) {
    if(ll[x] == rr[x]) return;
    tr[x] = min(tr[x<<1] , tr[x<<1|1]);
}
 
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r; tr[x] = lim;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid);
    Build(x<<1|1 , mid+1 , r);
}
 
void modify(int x , int l , int r , int w) {
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(l == ll[x] && r == rr[x])
        lazy[x] += w , tr[x] += w;
    else
        modify(x<<1 , l , r , w) , modify(x<<1|1 , l , r , w);
    downpush(x); update(x);
}
 
int query(int x , int l , int r) {
    downpush(x) , update(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return inf;
    if(l == ll[x] && r == rr[x])
        return tr[x];
    else return min(query(x<<1 , l , r) , query(x<<1|1 , l , r));
}
 
int main() {
    n = F(); m = F(); lim = F();
    for(int i=1; i<=n; ++i)
        q[i].l = F() , q[i].r = F()-1 , q[i].w = F();
    std::sort(q+1,q+n+1);
    Build(1,1,m);
    for(int i=1; i<=n; ++i) {
        int l = q[i].l , r = q[i].r;
        int tmp = min(q[i].w , query(1,l,r));
        if(tmp) {
            ans += tmp;
            modify(1,l,r,-tmp);
        }
    }printf("%d",ans);
}