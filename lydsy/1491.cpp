/**************************************************************
    Problem: 1491
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:940 kb
****************************************************************/
 
#include <stdio.h>
#define inf 233333333
 
int mp[101][101] , n , m ;
double a[101][101];
double ans[101];
 
inline int F() {register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
int main() {
    n = F(); m = F();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=inf;
    int x , y , z;
    for(int i=1; i<=m; ++i) {
        x = F() ; y = F() ; z = F();
        mp[x][y] = mp[y][x] = z;
        a[x][y] = a[y][x] = 1;
    }
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) {
                if (mp[i][j] > mp[i][k]+mp[k][j]) {
                    mp[i][j] = mp[i][k]+mp[k][j];
                    a[i][j] = 0;
                }
                if (mp[i][j] == mp[i][k]+mp[k][j]) {
                    a[i][j] += a[i][k] * a[k][j];
                }
            }
    for(int i=1; i<=n; ++i) a[i][i] = 0;
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) {
                if(mp[i][j] == mp[i][k] + mp[k][j] && a[i][j] > 0)
                    ans[k] += a[i][k]*a[k][j]/a[i][j];
            }
    for(int i=1; i<=n; ++i)
        printf("%.3lf\n",ans[i]);
}