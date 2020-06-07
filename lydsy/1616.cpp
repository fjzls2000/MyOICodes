/**************************************************************
    Problem: 1616
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1660 kb
****************************************************************/
 
#include <stdio.h>
int n , m , k , a , b , x , y , ch;
const int Maxn = 101;
int mp[Maxn][Maxn] , f[20][Maxn][Maxn];
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            while(ch = getchar() , ch != '.' && ch != '*');
            mp[i][j] = ch == '.';
        }
 
    scanf("%d%d%d%d",&a,&b,&x,&y);
    f[0][a][b] = 1;
 
    for(int i=1; i<=k; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=m; ++k) {
                if(mp[j][k])
                    f[i][j][k] = f[i-1][j+1][k] + f[i-1][j][k+1] + f[i-1][j-1][k] + f[i-1][j][k-1];
            }
    printf("%d\n",f[k][x][y] );
}