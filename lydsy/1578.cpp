/**************************************************************
    Problem: 1578
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1520 ms
    Memory:2776 kb
****************************************************************/
 
#include <stdio.h>
using namespace std;
inline int max(int a , int b) { return a > b ? a : b ; }
int a[11][51] , f[11] , dp[500010];
int tmp[51] , top;
int main() {
    int s , d , m;
    scanf("%d%d%d",&s,&d,&m);
    for(int i=1; i<=s; ++i)
        for(int j=1; j<=d; ++j)
            scanf("%d",&a[j][i]);
    f[1] = m;
    for(int i=2; i<=d; ++i) {
        top = 0;
        for(int j=1; j<=s; ++j)
            if(a[i][j]>a[i-1][j])
                tmp[++top] = j;
        for(int j=1; j<=f[i-1]; ++j)
            dp[j] = j;
        for(int j=1; j<=top; ++j) {
            for(int k=a[i-1][tmp[j]]; k<=f[i-1]; ++k)
                dp[k] = max(dp[k] , dp[k-a[i-1][tmp[j]]] + a[i][tmp[j]]);
        }
        f[i] = max(f[i] , dp[f[i-1]]);
    }
    printf("%d",f[d]);
}