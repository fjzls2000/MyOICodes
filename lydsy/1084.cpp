/**************************************************************
    Problem: 1084
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:176 ms
    Memory:4888 kb
****************************************************************/
 
#include <stdio.h>
inline int max(int a , int b) { return a > b ? a : b ; }
inline int F() {register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 101;
int n , m , K , sum[Maxn] , dp[Maxn][Maxn] , s1[Maxn] , s2[Maxn] , f[Maxn][Maxn][Maxn];
int main() {
    n = F(); m = F(); K = F();
    if(m == 1) {
        for(int i=1; i<=n; ++i)
            sum[i] = sum[i-1] + F();
        for(int i=1; i<=n; ++i)
            for(int k=1; k<=K; ++k) {
                dp[i][k] = dp[i-1][k];
                for(int j=0; j<i; ++j)
                    dp[i][k] = max(dp[i][k] , dp[j][k-1]+sum[i]-sum[j]);
            }
        printf("%d\n",dp[n][K]);
    }
    else {
        for(int i=1; i<=n; ++i) {
            s1[i] = s1[i-1] + F();
            s2[i] = s2[i-1] + F();
        }
        for(int k=1; k<=K; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j) {
                    f[i][j][k] = max(f[i-1][j][k] , f[i][j-1][k]);
                    for(int l=0; l<i; ++l) f[i][j][k] = max(f[i][j][k] , f[l][j][k-1] + s1[i] - s1[l]);
                    for(int l=0; l<j; ++l) f[i][j][k] = max(f[i][j][k] , f[i][l][k-1] + s2[j] - s2[l]);
                    if(i == j)
                        for(int l = 0; l<i; ++l)
                            f[i][j][k] = max(f[i][j][k] , f[l][l][k-1]+s1[i]+s2[j]-s1[l]-s2[l]);
                }
        printf("%d",f[n][n][K]);
    }
}