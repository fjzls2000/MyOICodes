/**************************************************************
    Problem: 1600
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:872 kb
****************************************************************/
 
#include <stdio.h>
inline int min(register int a , register int b) { return a < b ? a : b ; }
int n , lim , f[5][2510];
int main() {
    f[0][0]=1;
    scanf("%d",&n);
    int lim=(n+1)/2-1;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=min(lim,j);k++)
                f[i][j]+=f[i-1][j-k];
    printf("%d",f[4][n]);
}