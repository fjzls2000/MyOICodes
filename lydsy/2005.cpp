/**************************************************************
    Problem: 2005
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:28 ms
    Memory:2068 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
const int Maxn = 100001;
long long f[Maxn] , ans = 0 , n , m;
int main() {
    scanf("%lld%lld",&n,&m);
    if(m > n) swap(n,m);
    for(int i=n; i; --i) {
        f[i] = (n/i) * (m/i);
        for(int j=i+i; j<=n; j+=i)
            f[i] -= f[j];
        ans += f[i] * (i+i-1);
    } printf("%lld\n",ans);
}