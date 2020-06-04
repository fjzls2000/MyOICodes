#include <stdio.h>
#include <iostream>
using std::min; using std::max;
const int mod = 1000000007;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxt = 819210;
struct node { int a[2][2]; } lzy , lazy[Maxt] , tree[Maxt] , Std , f1 , Nul;
node operator + (node a , node b) {
    a.a[0][0] = (a.a[0][0] + b.a[0][0]) % mod;
    a.a[1][0] = (a.a[1][0] + b.a[1][0]) % mod;
    a.a[0][1] = (a.a[0][1] + b.a[0][1]) % mod;
    a.a[1][1] = (a.a[1][1] + b.a[1][1]) % mod;
    return a;
}
node operator * (node a , node b) {
    node c;
    for(int i=0; i<2; ++i)
        for(int j=0; j<2; ++j) {
            c.a[i][j] = 0;
            for(int k=0; k<2; ++k)
                c.a[i][j] = (c.a[i][j] + (long long)a.a[i][k]*b.a[k][j]) % mod;
        }return c;
}
node pow(node tmp , int i) {
    node ans = Std;
    for(; i; i>>=1 , tmp = tmp*tmp) if(i&1) ans = ans*tmp;
    return ans;
}
const int Maxn = 100010;
int n , m , ll[Maxt] , rr[Maxt] , a[Maxn];
 
void update(int x) {
    if(ll[x] == rr[x]) tree[x] = lazy[x];
    else tree[x] = (tree[x<<1] + tree[x<<1|1]) * lazy[x];
}
void Build(int x , int l  , int r) {
    ll[x] = l; rr[x] = r; lazy[x] = Std;
    if(l == r) {
        lazy[x] = pow(f1,a[l]);
    }
    else {
        int mid = (l + r) >> 1;
        Build(x<<1 , l , mid);
        Build(x<<1|1 , mid+1 , r);
    }
    update(x);
}
 
void modify(int x , int l , int r) {
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(ll[x] == l && rr[x] == r) lazy[x] = lazy[x] * lzy;
    else {
        modify(x<<1 , l , r);
        modify(x<<1|1 , l , r);
    }
    update(x);
}
 
node query(int x , int l , int r) {
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return Nul;
    if(l == ll[x] && r == rr[x]) return tree[x];
    return (query(x<<1 , l , r) + query(x<<1|1 , l , r)) * lazy[x];
}
 
int main() {
    f1.a[0][0] = f1.a[1][0] = f1.a[0][1] = 1; f1.a[1][1] = 0;
    Std.a[0][0] = Std.a[1][1] = 1; Std.a[0][1] = Std.a[1][0] = 0;
    Nul.a[0][0] = Nul.a[0][1] = Nul.a[1][0] = Nul.a[1][1] = 0;
    n = F() , m = F();
    for(int i=1; i<=n; ++i)
        a[i] = F();
    Build(1,1,n);
    while(m--) {
        int flag = F() , l = F() , r = F();
        if(flag == 1) {
            int v = F();
            lzy = pow(f1,v);
            modify(1,l,r);
        }
        else printf("%d\n",query(1,l,r).a[0][1]);
    }
}