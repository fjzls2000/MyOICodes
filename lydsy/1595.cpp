/**************************************************************
    Problem: 1595
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:368 ms
    Memory:3948 kb
****************************************************************/
 
#include <stdio.h>
#define ll long long
const ll inf = (ll)1e18;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
inline ll Fll() { register ll aa; int bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
struct node {
    ll w , h;
    int pre , nxt;
    inline void get(int x) {
        w = Fll() , h = Fll();
        pre = x-1 , nxt = x+1;
    }
} a[Maxn];
int n , now;
ll nowans , ans[Maxn];
int Pre() { return a[now].pre; }
int Nxt() { return a[now].nxt; }
int main() {
    n = F(); now = 1;
    for(int i=1; i<=n; ++i) {
        a[i].get(i);
        if(a[i].h < a[now].h) now = i;
    }
    a[0].w = a[n+1].w = 0;
    a[0].h = a[n+1].h = inf;
    a[0].nxt = 1; a[n+1].pre = n;
    for(int i=1; i<=n; ++i) {
        while(a[Pre()].h < a[now].h) now = Pre();
        while(a[Nxt()].h < a[now].h) now = Nxt();
        ans[now] = nowans + a[now].w;
        a[Pre()].nxt = Nxt();
        a[Nxt()].pre = Pre();
        if(a[Pre()].h < a[Nxt()].h) {
            nowans += a[now].w * (a[Pre()].h - a[now].h);
            a[Pre()].w += a[now].w;
            now = Pre();
        }
        else {
            nowans += a[now].w * (a[Nxt()].h - a[now].h);
            a[Nxt()].w += a[now].w;
            now = Nxt();
        }
    }
    for(int i=1; i<=n; ++i) {
        printf("%lld\n",ans[i]);
    }
}