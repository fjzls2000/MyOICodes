#include <stdio.h>
#include <algorithm>
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
struct node { int a , b , c , p , id; } a[Maxn];
inline bool cmpp(const node&a , const node&b) { return a.p < b.p; }
inline bool cmpi(const node&a , const node&b) { return a.id < b.id; }
int n , l , r;
int main() {
    n = F() , l = F() , r = F();
    for(int i=1; i<=n; ++i)
        a[i].a = F() , a[i].id = i;
    for(int j=1; j<=n; ++j)
        a[j].p = F();
    std::sort(a+1,a+n+1,cmpp);
    a[1].b = l; a[1].c = l - a[1].a;
    for(int i=2; i<=n; ++i) {
        a[i].c = a[i-1].c + 1;
        a[i].b = a[i].c + a[i].a;
        if(a[i].b < l) a[i].b = l , a[i].c = a[i].b - a[i].a;
        if(a[i].b > r) { puts("-1"); return 0; }
    }
    std::sort(a+1,a+n+1,cmpi);
    for(int i=1; i<=n; ++i)
        printf("%d ",a[i].b );
}