#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
int n , k , a[Maxn]; long long s = 0;
int main() {
    n = F() , k = F();
    for(int i=1; i<=n; ++i) a[i] = F();
    for(int i=1; i<=n; ++i) {
        ++s;
        if(s >= k) {
            printf("%d\n",a[k]);
            return 0;
        } else k -= s;
    }
}