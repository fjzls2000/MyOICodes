/**************************************************************
    Problem: 1620
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:828 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
inline int min(int a , int b) { return a > b ? b : a ; }
inline int max(int a , int b) { return a > b ? a : b ; }
struct work {
    int t , r;
} a[1010];
bool cmp(work a , work b) { return a.r > b.r; }
#define getch() getchar()
inline int F() {register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int n , ans = 10000000;
int main() {
    n = F();
    for(int i=1; i<=n; ++i) {
        a[i].t = F(); a[i].r = F();
    }
    std::sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; ++i)
        ans = min(ans , a[i].r)-a[i].t;
    if(ans < 0) ans = -1;
    printf("%d",ans);
}