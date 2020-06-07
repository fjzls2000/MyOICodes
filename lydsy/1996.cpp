/**************************************************************
    Problem: 1996
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:108 ms
    Memory:8652 kb
****************************************************************/
 
#include <stdio.h>
#define getch() getchar()
inline int F() {register int aa,bb,ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10+ch-'0'; return bb ? aa : -aa;
}
const int mod = 19650827;
const int Maxn = 1001;
#define R register
int n , f[Maxn][Maxn][2] , a[Maxn];
int main() {
    n = F();
    for(R int i=1; i<=n; ++i) a[i] = F() , f[i][i][0] = 1;
    for(R int j=2; j<=n; ++j)
        for(int i=j-1; i; --i) {
            if(a[i]<a[i+1]) f[i][j][0] += f[i+1][j][0];
            if(a[i]<a[j]) f[i][j][0] += f[i+1][j][1];
            if(a[j]>a[j-1]) f[i][j][1] += f[i][j-1][1];
            if(a[j]>a[i]) f[i][j][1] += f[i][j-1][0];
            f[i][j][0] %= mod;
            f[i][j][1] %= mod;
        }
    printf("%d\n",(f[1][n][0]+f[1][n][1])%mod);
}