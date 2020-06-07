/**************************************************************
    Problem: 1801
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:280 ms
    Memory:8872 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 101;
const int mod = 9999973;
int n , m , ans = 0;
long long f[Maxn][Maxn][Maxn];
int main() {
//  freopen("wwxwwx.in","r",stdin);
//  freopen("wwxwwx.out","w",stdout);
    scanf("%d%d",&n,&m);
    f[0][0][0] = 1;
    for(int i=1; i<=n; ++i)
        for(int j=0; j<=m; ++j)
            for(int k=0; k<=m-j; ++k) {
                int tmp = (m-k-j+2); tmp*=tmp-1; tmp/=2;
                f[i][j][k] += f[i-1][j][k];
                if(j>0) f[i][j][k] = (f[i][j][k] + f[i-1][j-1][k] * (m-j-k+1)) % mod;
                if(k>0) f[i][j][k] = (f[i][j][k] + f[i-1][j+1][k-1] * (j+1) + f[i-1][j][k-1]*j*(m-j-k+1)) % mod;
                if(j>1) f[i][j][k] = (f[i][j][k] + f[i-1][j-2][k] * tmp ) % mod;
                if(k>1) f[i][j][k] = (f[i][j][k] + f[i-1][j+2][k-2] * ((j+2)*(j+1)/2)) % mod;
                if(i == n) ans = (ans + f[i][j][k])%mod;
            }
    printf("%d",ans);
    fclose(stdin); fclose(stdout); return 0;
}