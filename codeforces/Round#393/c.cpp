#include <stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
const int Maxt = 4*Maxn;
int n , ans[Maxn] , mx[Maxt] , ll[Maxt] , rr[Maxt] , lazy[Maxt];
void update(int x) {
    if(ll[x] == rr[x]) return;
    mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void downpush(int x) {
    if(ll[x] == rr[x]) return;
    mx[x<<1] += lazy[x];
    lazy[x<<1] += lazy[x];
    mx[x<<1|1] += lazy[x];
    lazy[x<<1|1] += lazy[x];
    lazy[x] = 0;
}
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid); Build(x<<1|1 , mid+1 , r);
}
void modify(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) { mx[x] += val; lazy[x] += val; }
    else modify(x<<1 , l , r , val) , modify(x<<1|1 , l , r , val) , update(x);
}
int find(int x) {
    downpush(x);
    if(ll[x] == rr[x]) return ll[x];
    if(mx[x<<1|1] > 0) return find(x<<1|1);
    else return find(x<<1);
}
int main() {
    n = F();
    Build(1,1,n);
    for(int i=1; i<=n; ++i) {
        int x = F() , op = F();
        if(!op) modify(1,1,x,-1);
        else {
            int val = F();
            ans[x] = val;
            modify(1,1,x,1);
        }
        if(mx[1] > 0) printf("%d\n",ans[find(1)]);
        else puts("-1");
    }
}