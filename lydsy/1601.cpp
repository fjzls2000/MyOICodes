/**************************************************************
    Problem: 1601
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:124 ms
    Memory:24264 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 500;
const int Maxm = 2000010;
int n , m , ecnt = 0 , fa[Maxn];
struct edge{
    int a , b , wi;
}e[Maxm];
bool cmp(edge a , edge b) {
    return a.wi < b.wi;
}
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
int main() {
    long long ans = 0;
    n = F();
    for(int i=1; i<=n; ++i) {
        m = F();
        e[++ecnt].a = i;
        e[ecnt].b = n+1;
        e[ecnt].wi = m ;
        fa[i] = i;
    }
    fa[n+1] = n+1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) {
            m = F();
            if(i == j) continue;
            e[++ecnt].a = i;
            e[ecnt].b  =  j;
            e[ecnt].wi = m ;
        }
    std::sort(e+1,e+ecnt+1,cmp);
    for(int i=1; i<=ecnt; ++i) {
        if(find(e[i].a) != find(e[i].b)) {
            int x = fa[e[i].a] , y = fa[e[i].b];
            fa[x] = y;
            ans += e[i].wi;
        }
    }
    printf("%lld\n",ans );
}