#include <stdio.h>
inline int min(const int&a , const int&b) { return a < b ? a : b; }
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
int n , a[Maxn] , f[Maxn];
int find(int n , int t) {
    int l = 1 , r = n , mid , ans = n;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(a[mid]>a[n]-t) r = mid - 1 , ans = mid;
        else l = mid + 1;
    } return ans-1;
}
int main() {
    n = F();
    for(int i=1; i<=n; ++i) {
        a[i] = F();
        f[i] = min(f[i-1]+20 , min(f[find(i,90)]+50 , f[find(i,1440)]+120));
    }
    for(int i=1; i<=n; ++i) printf("%d\n",f[i]-f[i-1]);
}