/**************************************************************
    Problem: 1679
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:32 ms
    Memory:1328 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#include <algorithm>
const int Maxn = 10010;
int a[Maxn] , n;
long long tot , ans;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    std::sort(a+1,a+n+1);
    for(int i=1; i<=n; ++i) {
        tot -= a[i];
        ans += tot - (long long)(n-i)*a[i];
    }
    std::cout<<ans*2;
}