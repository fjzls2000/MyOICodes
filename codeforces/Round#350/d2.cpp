#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define inf 2e9
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
int n , k , a[Maxn] , b[Maxn];
bool check(unsigned int x) {
    int tmp = k;
    for(int i=1; i<=n; ++i) {
        long long used = 1ll * x * a[i] - b[i];
        if(tmp >= used) {
            if(used >= 0) tmp -= used;
        } else return 0;
    } return 1;
}
int main() {
    n = F() , k = F();
    for(int i=1; i<=n; ++i) a[i] = F();
    for(int i=1; i<=n; ++i) b[i] = F();
    unsigned int l = 0 , r = inf , mid , ans;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) ans = mid , l = mid + 1;
        else r = mid - 1;
    } printf("%d\n",ans);
}