/**************************************************************
    Problem: 1045
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:2164 ms
    Memory:78932 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
const int Maxn = 10000010;
int a[Maxn] , c[Maxn] , n , ave; long long tot = 0 , ans = 0;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]) , tot += a[i];
    ave = tot/n;
    for (int i=2; i<=n; i++)
        c[i] = c[i-1] + a[i] - ave;
    std::sort(c+1,c+n+1);
    int mid = c[(n>>1)+1];
    for(int i=1; i<=n; i++)
        ans += abs(c[i] - mid);
    printf("%lld",ans);
    return 0;
}