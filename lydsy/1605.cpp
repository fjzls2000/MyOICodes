/**************************************************************
    Problem: 1605
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:72 ms
    Memory:3100 kb
****************************************************************/
 
#include <stdio.h>
#define inf 233333333
 
inline int max(int a , int b) { return a > b ? a : b ; }
inline int abs(int x) { return x >= 0 ? x : -x ; }
 
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 100010;
int n , m , t , cx[Maxn] , cy[Maxn] , hx[Maxn] , hy[Maxn] , cnt[65][65] , f[34][65][65] , ans;
char step[34][65][65];
const int ss[2][4] = { 1 , 0 , 0 , -1 , 0 , 1 , -1 , 0 };
const char cc[4] = {'W','S','N','E'};
 
int main() {
    n = F(); m = F(); t = F();
    for(int i=1; i<=n; ++i) {
        cx[i] = F(); cy[i] = F();
    }
    for(int i=1; i<=m; ++i) {
        hx[i] = F(); hy[i] = F();
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            int dx = cx[i] - hx[j], dy = cy[i]-hy[j];
            if(abs(dx) <= 30 && abs(dy) <= 30)
                ++cnt[31+dx][31+dy];
        }
    for(int k=0; k<=t; ++k)
        for(int i=0; i<=62; ++i)
            for(int j=0; j<=62; ++j) {
                f[k][i][j] = -inf;
                step[k][i][j] = 'Z';
            }
    f[0][31][31] = 0;
    for(int k=1; k<=t; ++k)
        for(int i=1; i<=61; ++i)
            for(int j=1; j<=61; ++j) {
                f[k][i][j] = cnt[i][j] + max( max( f[k-1][i-1][j] , f[k-1][i+1][j]) , max(f[k-1][i][j-1] , f[k-1][i][j+1]) );
            }
    ans = 0;
     
    for(int i=1; i<=61; ++i)
        for(int j=1; j<=61; ++j)
            ans = max(ans , f[t][i][j]);
    for(int i=1; i<=61; ++i)
        for(int j=1; j<=61; ++j)
            if(f[t][i][j] == ans)
                step[t][i][j] = 'A';
    for(int k=t-1; k>=0; --k)
        for(int i=1; i<=61; ++i)
            for(int j=1; j<=61; ++j)
                for(int kk=0; kk<4; ++kk)
                    if(f[k][i][j] + cnt[i+ss[0][kk]][j+ss[1][kk]] == f[k+1][i+ss[0][kk]][j+ss[1][kk]] && step[k+1][i+ss[0][kk]][j+ss[1][kk]] < 'Z')
                        step[k][i][j] = cc[kk];
    printf("%d\n",ans);
    int i = 31 , j = 31;
    for(int k=0; k<t; ++k) {
        printf("%c",step[k][i][j]);
        if(step[k][i][j] == 'E') --i;
        if(step[k][i][j] == 'W') ++i;
        if(step[k][i][j] == 'S') ++j;
        if(step[k][i][j] == 'N') --j;
    }
}