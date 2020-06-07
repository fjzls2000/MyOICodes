/**************************************************************
    Problem: 2326
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:804 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
typedef long long ll;
struct node { ll num[4][4]; } a , b ;
ll n , m;
inline ll mpmul(ll x , ll y) {ll ans; for(; y; y>>=1 , x=(x<<1)%m) if(y&1) ans = (ans+x)%m; return ans;}
node operator * (node a , node b) {
    node tmp;
    for(int i=1; i<=3; ++i)
        for(int j=1; j<=3; ++j) {
            tmp.num[i][j] = 0;
            for(int k=1; k<=3; ++k)
                tmp.num[i][j] = (tmp.num[i][j] + mpmul(a.num[i][k] , b.num[k][j])) % m;
        }
    return tmp;
}
void calc(ll t , ll x) {
    memset(b.num , 0 , sizeof(b.num));
    b.num[1][1] = t;
    b.num[2][1] = b.num[2][2] = b.num[3][1] = b.num[3][2] = b.num[3][3]=1;
    ll tmp = x - t/10 +1;
    for(; tmp; tmp>>=1 , b = b*b) if(tmp & 1) a = a*b;
}
int main() {
    scanf("%lld%lld",&n,&m);
    a.num[1][1] = a.num[2][2] = a.num[3][3] = 1;
    ll t = 10;
    for(; t <= n; t*=10) calc(t,t-1);
    calc(t , n);
    printf("%d",a.num[3][1]);
}