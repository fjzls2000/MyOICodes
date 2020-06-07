/**************************************************************
    Problem: 1617
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:24 ms
    Memory:840 kb
****************************************************************/
 
#include <stdio.h>
inline int min(register int a , register int b) { return a < b ? a : b ; }
const int Maxn = 2501;
int n , m , a[Maxn] , f[Maxn];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    for(int i=1; i<=n; ++i) {
        f[i] = a[i] + m + m;
        for(int j=1; j<i; ++j)
            f[i] = min(f[i] , m+m+a[j]+f[i-j]);
    }
    printf("%d",f[n]-m);
}