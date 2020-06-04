#include <stdio.h>
#include <iostream>
using std::max; using std::min;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
int n , a[Maxn] , ans1 , ans2 , ans; char s[Maxn];
int main() {
    n = F();
    scanf("%s",s+1);
    for(int i=1; i<=n; ++i) {
        if(s[i] == 'b') a[i] = 1;
        else a[i] = 0;
    }
    for(int i=1 , p = 0; i<=n; ++i , p ^= 1) {
        if(a[i] != p) {
            if(p) ++ans1;
            else ++ans2;
        }
    }
    ans = max(ans1,ans2);
    ans1 = ans2 = 0;
    for(int i=1; i<=n; ++i) {
        if(s[i] == 'b') a[i] = 1;
        else a[i] = 0;
    }
    for(int i=1 , p = 1; i<=n; ++i , p ^= 1) {
        if(a[i] != p) {
            if(p) ++ans1;
            else ++ans2;
        }
    }
    ans = min(ans , max(ans1,ans2));
    printf("%d\n",ans);
}