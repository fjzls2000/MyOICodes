/**************************************************************
    Problem: 2287
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:332 ms
    Memory:32096 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 2001;
int f[Maxn][Maxn] , c[Maxn][Maxn] , n , m , a[Maxn];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    f[0][0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=m; j++) 
            if(j >= a[i]) f[i][j] = (f[i-1][j] + f[i-1][j-a[i]]) % 10;
            else f[i][j] = f[i-1][j];
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(j >= a[i]) c[i][j] = (f[n][j] - c[i][j-a[i]]+10) % 10;
            else c[i][j] = f[n][j];
            if(j) printf("%d",c[i][j]);
        }
        puts("");
    }
}