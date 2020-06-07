/**************************************************************
    Problem: 1623
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:1016 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define getch() getchar()
inline int F() {
    register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int v[50005];
int n , m , d , l , ans;
int main() {
    n = F() , m = F() , d = F() , l = F();
    for(int i=1; i<=n; ++i)
        v[i] = F();
    std::sort(v+1,v+n+1);
    for(int i=1; i<=n; ++i) {
        int t = ans/m;
        if(v[i]-t*d>=l) ++ans;
    }
    printf("%d",ans);
}