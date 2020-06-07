/**************************************************************
    Problem: 1618
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:48 ms
    Memory:1040 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
inline int min(int a , int b) { return a > b ? b : a ; }
const int Maxn = 202;
const int Maxm = 55555;
int n , m , p[Maxn] , c[Maxn] , f[Maxm] , ans;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
        scanf("%d%d",&p[i],&c[i]);
    memset(f,42,sizeof(f)); f[0] = 0;
    for(int i=1; i<=n; ++i)
        for(int j=p[i]; j<=m+5000; ++j)
            f[j] = min(f[j-p[i]]+c[i] , f[j]);
    ans = 2147483647;
    for(int i=m; i<=m+5000; ++i) ans = min(ans , f[i]);
    printf("%d",ans);
}