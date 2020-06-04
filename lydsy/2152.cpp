/**************************************************************
    Problem: 2152
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:476 ms
    Memory:6160 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using std::min; using std::max;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
const int Maxm = 200010;
bool vis[Maxn];
int n , size[Maxn] , mx[Maxn] , root , sz;
int to[Maxm] , next[Maxn] , g[Maxn] , w[Maxm] , ecnt = 0 , d[Maxn] , v[Maxn] , ans = 0;
int getgcd(int a , int b) {return b ? getgcd(b,a%b) : a;}
inline void ins(const int&a , const int&b , const int&wi) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi; }
void getrt(int x , int f) {
    size[x] = 1; mx[x] = 0;
    for(int i=g[x]; i; i=next[i]) {
        if(vis[to[i]] || to[i] == f) continue;
        getrt(to[i],x);
        size[x] += size[to[i]];
        mx[x] = max(mx[x] , size[to[i]]);
    }mx[x] = max(mx[x] , sz - size[x]);
    if(mx[x] < mx[root]) root = x;
}
void getdis(int x , int f) {
    ++v[d[x]];
    for(int i=g[x]; i; i=next[i]) {
        if(vis[to[i]] || to[i] == f) continue;
        d[to[i]] = (d[x]+w[i]) % 3;
        getdis(to[i],x);
    }
}
int calc(int x , int now) {
    v[0] = v[1] = v[2] = 0;
    d[x] = now; getdis(x,0);
    return v[0]*v[0]+v[1]*v[2]*2;
}
void work(int x) {
    ans += calc(x,0); vis[x] = 1;
    for(int i=g[x]; i; i=next[i]) {
        if(vis[to[i]]) continue;
        ans -= calc(to[i],w[i]);
        root = 0; sz = size[to[i]];
        getrt(to[i],0);
        work(root);
    }
}
int main() {
    n = F();
    for(int i=1; i<n; ++i) {
        int a = F() , b = F() , wi = F() % 3;
        ins(a,b,wi) , ins(b,a,wi);
    }
    mx[0] = sz = n;
    getrt(1,0);
    work(root);
    int gcd = getgcd(ans , n*n);
    printf("%d/%d\n",ans/gcd,n*n/gcd );
}