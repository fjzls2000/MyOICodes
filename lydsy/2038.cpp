/**************************************************************
    Problem: 2038
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1560 ms
    Memory:2988 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <math.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0' || ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0' && ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 50010;
int n , m , pos[Maxn] , c[Maxn];
long long s[Maxn] , ans;
long long gcd(long long a , long long b) { return b ? gcd(b,a%b) : a; }
inline long long sqr(long long x) { return x * x; }
struct node { int l , r , i; long long a , b; } a[Maxn];
bool cmp1(node a , node b) { return (pos[a.l] == pos[b.l]) ? (a.r < b.r) : (a.l < b.l); }
bool cmp2(node a , node b) { return a.i < b.i; }
void init() {
    n = F() , m = F();
    for(int i=1; i<=n; ++i)
        c[i] = F();
    int block = sqrt(n);
    for(int i=1; i<=n; ++i)
        pos[i] = (i-1)/block+1;
    for(int i=1; i<=m; ++i) {
        a[i].l = F(); a[i].r = F();
        a[i].i = i;
    }
}
void update(int p , int add) {
    ans -= sqr(s[c[p]]);
    s[c[p]] += add;
    ans += sqr(s[c[p]]);
}
void solve() {
    for(int i=1,l=1,r=0; i<=m; ++i) {
        for(; r<a[i].r; ++r)
            update(r+1,1);
        for(; r>a[i].r; --r)
            update(r,-1);
        for(; l<a[i].l; ++l)
            update(l,-1);
        for(; l>a[i].l; --l)
            update(l-1,1);
        if(a[i].l == a[i].r) {
            a[i].a = 0; a[i].b = 1;
            continue;
        }
        a[i].a = ans - (a[i].r - a[i].l + 1);
        a[i].b = (long long) (a[i].r - a[i].l + 1) * (a[i].r - a[i].l);
        long long tmp = gcd(a[i].a , a[i].b);
        a[i].a /= tmp; a[i].b /= tmp;
    }
}
int main() {
    init();
    std::sort(a+1,a+m+1,cmp1);
    solve();
    std::sort(a+1,a+m+1,cmp2);
    for(int i=1; i<=m; ++i)
        printf("%lld/%lld\n",a[i].a,a[i].b);
}