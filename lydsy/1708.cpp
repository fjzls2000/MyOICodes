/**************************************************************
    Problem: 1708
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:900 kb
****************************************************************/
 
#include <stdio.h>
int n , v;
int a[30]; long long f[10010];
int main() {
    scanf("%d%d",&n,&v);
    for(int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    f[0] = 1;
    for(int i=1; i<=n; ++i)
        for(int j=a[i]; j<=v; ++j)
            f[j] += f[j-a[i]];
    printf("%lld\n",f[v] );
    return 0;
}