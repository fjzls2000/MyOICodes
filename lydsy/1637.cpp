/**************************************************************
    Problem: 1637
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:76 ms
    Memory:1992 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <memory.h>
inline int max(int a , int b) { return a > b ? a : b ; }
#define zero 50000
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
struct node { int x , v; } a[Maxn];
inline bool cmp(node a , node b) { return a.x < b.x; }
int n , dis[Maxn] , ans = 0;
int main() {
    n = F();
    for(int i=1; i<=n; ++i) {
        a[i].v = F(); a[i].x = F();
        if(!a[i].v) a[i].v = -1;
    }
    std::sort(a+1,a+n+1,cmp);
    memset(dis,-1,sizeof(dis));
    int tot = zero;
    for(int i=1; i<=n; ++i) {
        tot += a[i].v;
        if(dis[tot] == -1) dis[tot] = a[i+1].x;
        else ans = max(ans , a[i].x-dis[tot]);
    }
    printf("%d",ans);
}