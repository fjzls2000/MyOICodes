#include <stdio.h>
#include <math.h>
#define ll long long
ll gcd(ll a , ll b) { return b ? gcd(b,a%b) : a; }
ll p(ll a , ll b) {
	ll ans = 1;
	for(; b; b>>=1 , a*=a) if(b&1) ans *= a;
	return ans;
}
ll l , r , n , ans;
int main() {
	scanf("%lld%lld%lld",&n,&l,&r);
	if(n > 24) { puts("0"); return 0; }
	if(n == 1) { printf("%lld\n",r-l+1); return 0; }
	if(n == 2) { printf("%lld\n",(r-l+1)*(r-l)); return 0; }
	int lim = pow(2,log2(1e7)/(n-1)+1);
	for(int i=1; i<=lim; ++i)
		for(int j=i+1; j<=lim; ++j)
			if(gcd(i,j) == 1) {
				long long ii = p(i,n-1) , jj = p(j,n-1);
				if(l*jj/ii > r) continue;
				ans += (r*ii/jj)/ii - (l-1)/ii;
			}
	printf("%lld\n",ans*2 );
}