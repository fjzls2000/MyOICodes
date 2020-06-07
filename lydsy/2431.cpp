/**************************************************************
    Problem: 2431
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:820 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#include <algorithm>
int f[2][1010] , s[2][1010] , a;
const int mod = 10000;
void Solve() {
    int n,k;
    scanf("%d%d",&n,&k);
    f[0][0] = 1;
    f[0][1] = 1;
    f[0][2] = 0;
    s[0][0] = 1;
    s[0][1] = 2;
    for(int i=2; i<=k; i++)
        s[0][i] = 2;
      
    for(int i=3; i<=n; i++)
        for(int j=0; j<=k; j++) {
            a = j-i;
            if(a<0) a = 0;
            else a = s[~i&1][a];
            /*=========================================*/
            f[i&1][j] = s[~i&1][j] - a;
            if(f[i&1][j] >= mod) f[i&1][j] -= mod;
            if(f[i&1][j] < 0) f[i&1][j] += mod;
            /*=========================================*/
            s[i&1][j] = s[i&1][j-1] + f[i&1][j];
            if(s[i&1][j] >= mod) s[i&1][j]-=mod;
        }
    printf("%d\n",f[n&1][k]);
}
 
int main() {
    int t = 1;
    while(t--) Solve();
}