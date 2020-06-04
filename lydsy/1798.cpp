/**************************************************************
    Problem: 1798
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:6304 ms
    Memory:13316 kb
****************************************************************/
 
#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
const int MAXBUF = 1<<22; char B[MAXBUF] , *S = B , *T = B;
#define getch() (S == T && (T = (S = B) + fread(B,1,MAXBUF,stdin) , S == T) ? EOF : *S ++)
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100001;
const int Maxt = 409601;
int n , mod , a[Maxn] , ll[Maxt] , rr[Maxt] , tree[Maxt] , lazy[Maxt] , mul[Maxt];
inline void downpush(int x) {
    if(ll[x] == rr[x]) { lazy[x] = 0; mul[x] = 1; return; }
    lazy[x<<1] = ((long long)lazy[x<<1] * mul[x] + lazy[x]) % mod;
    lazy[x<<1|1] = ((long long)lazy[x<<1|1] * mul[x] + lazy[x]) % mod;
    mul[x<<1] = ((long long)mul[x<<1] * mul[x]) % mod;
    mul[x<<1|1] = ((long long)mul[x<<1|1] * mul[x]) % mod;
    tree[x<<1] = ((long long)tree[x<<1] * mul[x] + ((long long)lazy[x] * (rr[x<<1]-ll[x<<1]+1))) % mod;
    tree[x<<1|1] = ((long long)tree[x<<1|1] * mul[x] + ((long long)lazy[x] * (rr[x<<1|1]-ll[x<<1|1]+1))) % mod;
    lazy[x] = 0; mul[x] = 1;
}
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r; mul[x] = 1; lazy[x] = 0;
    if(l == r) {
        tree[x] = a[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid); Build(x<<1|1 , mid+1 , r);
    tree[x] = (tree[x<<1] + tree[x<<1|1]) % mod;
}
void modifymul(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(r < l) return;
    if(l == ll[x] && r == rr[x]) {
        mul[x] = val % mod;
        tree[x] = ((long long)val * tree[x]) % mod;
    }
    else {
        modifymul(x<<1 , l , r , val);
        modifymul(x<<1|1 , l , r , val);
        tree[x] = (tree[x<<1] + tree[x<<1|1]) % mod;
    }
}
void modifyadd(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(r < l) return;
    if(l == ll[x] && r == rr[x]) {
        lazy[x] = val % mod;
        tree[x] = ((long long)val * (r-l+1) + tree[x]) % mod;
    }
    else {
        modifyadd(x<<1 , l , r , val);
        modifyadd(x<<1|1 , l , r , val);
        tree[x] = (tree[x<<1] + tree[x<<1|1]) % mod;
    }
}
int query(int x , int l , int r) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(r < l) return 0;
    if(l == ll[x] && r == rr[x]) return tree[x] % mod;
    else return (query(x<<1 , l , r) + query(x<<1|1 , l , r)) % mod;
}
int main() {
//  freopen("1798.in","r",stdin);
    n = F() , mod = F();
    for(int i=1; i<=n; ++i) a[i] = F();
    Build(1,1,n);
    int t = F();
    while(t--) {
        int op = F();
        if(op == 1) {
            int l = F() , r = F() , val = F();
            modifymul(1,l,r,val);
        } else if(op == 2) {
            int l = F() , r = F() , val = F();
            modifyadd(1,l,r,val);
        } else {
            int l = F() , r = F();
            printf("%d\n",query(1,l,r));
        }
    }
}