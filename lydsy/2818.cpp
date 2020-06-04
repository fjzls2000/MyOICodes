/**************************************************************
    Problem: 2818
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:968 ms
    Memory:166836 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 10000001;
int n , p[Maxn] , top = 0 , phi[Maxn]; bool vis[Maxn];
long long ans = 0 , sum[Maxn];
void getphi() {
    phi[1] = 1;
    for(int i=2; i<=n; ++i) {
        if(!vis[i]) { phi[i] = i-1; p[++top] = i; }
        for(int j=1; j<=top; ++j) {
            int x = p[j];
            if(i*x>n) break;
            vis[i*x] = 1;
            if(i%x == 0) { phi[i*x]=phi[i]*x; break; }
            phi[i*x] = phi[i] * phi[x];
        }
    }
}
int main() {
    scanf("%d",&n);
    getphi();
    for(int i=1; i<=n; ++i)
        sum[i] = sum[i-1] + phi[i];
    for(int i=1; i<=top; ++i) {
        int t = n/p[i];
        ans += sum[t]+sum[t]-1;
    }
    printf("%lld\n",ans );
}