#include <stdio.h>
#include <algorithm>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200005;
int n , m , cnt , a[Maxn] , b[Maxn] , s[Maxn] , c[Maxn] , d[Maxn] , ans = 1;
int find(int x) {
    int l = 1 , r = cnt , mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(b[mid] == x) return mid;
        if(b[mid] > x) r = mid - 1;
        else l = mid + 1;
    } return 0;
}
int main() {
    n = F();
    for(int i=1; i<=n; ++i) b[i] = a[i] = F();
    std::sort(b+1,b+n+1); cnt = 1;
    for(int i=2; i<=n; ++i) if(b[i] != b[cnt]) b[++cnt] = b[i];
    for(int i=1; i<=n; ++i) ++s[find(a[i])];
    m = F();
    for(int i=1; i<=m; ++i) c[i] = s[find(F())];
    for(int i=1; i<=m; ++i) {
        d[i] = s[find(F())];
        if(c[i] > c[ans] || (c[i] == c[ans] && d[i] > d[ans])) ans = i;
    } printf("%d\n",ans);
}