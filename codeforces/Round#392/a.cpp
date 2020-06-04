#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
int a[Maxn] , mx = 0 , ans = 0;
int main() {
    int n = F();
    for(int i=1; i<=n; ++i) a[i] = F() , mx = max(mx , a[i]);
    for(int i=1; i<=n; ++i) ans += mx - a[i];
    printf("%d\n",ans );
}