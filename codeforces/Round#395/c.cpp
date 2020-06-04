#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
int n , m , ans = -1 , ansd , a[Maxn] , b[Maxn];
int Pow(int a , int b) {
    int ans = 1;
    for(; b; b>>=1 , a = (long long)a*a % m) if(b&1) ans = (long long)ans * a % m;
    return ans;
}
inline int find(int *a , int n , int x) { return *lower_bound(a+1,a+n+1,x) == x; }
void sol(int *a , int n) {
    if(n == 1) { ans = a[1] , ansd = 1; return; }
 
    int tmp = a[2] - a[1] , cnt = 0;
    for(int i=1; i<=n; ++i)
        if(find(a,n,(a[i]+tmp)%m))
            ++cnt;
    ansd = (long long)tmp * Pow(n-cnt,m-2) % m;
    int d = (m - ansd) % m;
    for(int i=1; i<=n; ++i) {
        if(!find(a,n,(a[i]+d)%m)) {
            if(ans == -1) ans = a[i];
            else { ans = -1; return; }
        }
    }
}
int main() {
    m = F() , n = F();
    for(int i=1; i<=n; ++i) a[i] = F();
    sort(a+1,a+n+1);
    if(n == 1 || n == m) { printf("%d 1\n",a[1]); return 0; }
    if(n+n < m) sol(a,n);
    else {
        int top = 0;
        for(int i=0; i<m; ++i)
            if(!find(a,n,i)) b[++top] = i;
        sol(b,top);
        if(ans != -1) ans = (ans + (long long)ansd * top) % m;
    }
    if(ans == -1) printf("%d\n",ans);
    else printf("%d %d\n",ans,ansd);
}