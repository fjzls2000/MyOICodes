/**************************************************************
    Problem: 3585
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:5832 ms
    Memory:34032 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define R register
#define inf 233333333
inline int max(R int a , R int b) { return a > b ? a : b ; }
inline int min(R int a , R int b) { return a < b ? a : b ; }
const int Maxn = 400010 ; const int Max4n = 4*Maxn ;
#define getch() getchar()
inline int F() {register int aa,bb,ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-');ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10+ch-'0'; return bb ? aa : -aa;
}
 
struct data {
    int l , r , id;
} q[Maxn];
inline bool cmp(data a , data b) { return a.l < b.l; }
 
int n , m , ll[Max4n] , rr[Max4n] , tmin[Max4n] , sg[Maxn] , a[Maxn] , b[Maxn] , last[Maxn] , next[Maxn] , ans[Maxn] , bcnt = 0;
bool mark[Maxn];
 
int Search(R int x) {
    int l = 0 , r = bcnt;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(x <= b[mid]) r = mid;
        else l = mid+1;
    }return l;
}
 
inline void downpush(int x) {
    if(ll[x] == rr[x]) return;
    tmin[x<<1] = min(tmin[x<<1] , tmin[x]);
    tmin[x<<1|1] = min(tmin[x<<1|1] , tmin[x]);
}
inline void Build(int x , int l , int r) {
    ll[x] = l , rr[x] = r; tmin[x] = inf;
    if(l == r) tmin[x] = sg[l];
    else {
        int mid = (l + r) >> 1;
        Build(x<<1 , l , mid);
        Build(x<<1|1 , mid+1 , r);
    }
}
inline int query(R int k) {
    R int x = 1;
    while(ll[x] != rr[x]) {
        if(tmin[x] != inf) downpush(x);
        if(k <= (ll[x] + rr[x]) >> 1) x = x<<1;
        else x = x<<1|1;
    } return tmin[x];
}
inline void update(int x , int l , int r , int k) {
    if(tmin[x] != inf) downpush(x);
    l = max(l , ll[x]); r = min(r , rr[x]);
    if( l > r ) return;
    if(l == ll[x] && r == rr[x]) tmin[x] = min(tmin[x] , k);
    else if(ll[x] != rr[x]) update(x<<1 , l , r , k) , update(x<<1|1 , l , r , k);
}
 
void Init() {
    R int k = 0;
    n = F() ; m = F();
    for(R int i=1; i<=n; ++i) a[i] = b[i] = F();
    std::sort(b+1,b+n+1);
    for(R int i=1; i<=n; ++i)
        if(b[i] != b[bcnt]) b[++bcnt] = b[i];
    for(R int i=1; i<=n; ++i) {
        int t = Search(a[i]);
        mark[t] = 1;
        if(a[i] == k) while(mark[k]) if(b[++t] != ++k) break;
        sg[i] = k;
    }
    Build(1 , 1 , n);
    for(R int i=n; i; --i) next[i] = last[Search(a[i])] , last[Search(a[i])] = i;
    for(R int i=1; i<=m; ++i) {
        q[i].l = F(); q[i].r = F();
        q[i].id = i;
    }
    std::sort(q+1,q+m+1,cmp);
}
void Solve() {
    R int now = 1;
    for(R int i=1; i<=m; ++i) {
        while(now < q[i].l) {
            if(!next[now]) next[now] = n+1;
            update(1 , now , next[now]-1 , a[now]);
            ++now;
        }
        ans[q[i].id] = query(q[i].r);
    }
}
void End() { for(R int i=1; i<=m; ++i) printf("%d\n",ans[i]); }
 
int main() {
    Init();
    Solve();
    End();
}