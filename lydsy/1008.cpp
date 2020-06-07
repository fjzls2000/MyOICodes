/**************************************************************
    Problem: 1008
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:804 kb
****************************************************************/
 
#include <stdio.h>
typedef long long ll;
const int mod = 100003;
ll pow(ll n , ll k) {
    ll ans = 1;
    for(ll tmp = n; k; k>>=1 , tmp = (tmp * tmp) % mod)
        if (k&1) ans = (ans * tmp) % mod;
    return ans;
}
int main() {
    ll n , k;
    scanf("%lld%lld",&k,&n);
    ll a = pow(k-1 , n-1) , b = pow(k , n);
    a *= k;
    a %= mod;
    b -= a;
    while(b < 0) b+=mod;
    while(b >= mod) b-=mod;
    printf("%lld",b);
}