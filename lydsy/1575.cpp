/**************************************************************
    Problem: 1575
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:52 ms
    Memory:8656 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#define inf 233333333
 
int abs(int a) { return a >= 0 ? a : -a; }
int min(int a , int b) { return a < b ? a : b ; }
 
#define getch() getchar()
inline int F() {
    register int aa , bb , ch;
    while(ch = getch() , (ch<'0' || ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0' && ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 1001;
int n , E , a[Maxn] , eb[Maxn] , e[Maxn][Maxn] , f[Maxn][Maxn];
 
int main() {
    n = F() ; E = F();
    for(int i=1; i<=n; ++i) {
        a[i] = F();
    }
    memset(f,42,sizeof(f));
    for(int i=n; i; --i)
        for(int j=n; j>i; --j) {
            eb[i] += 2*abs(a[j]-a[i]);
        }
    for(int i=1; i<=n; ++i) {
        f[i][1] = eb[i];
        for(int j=1; j<i; ++j) {
            f[i][1] += 2*abs(a[j]-a[i]);
            for(int k=j+1; k<i; ++k) {
                e[i][j] += abs(2*a[k]-a[i]-a[j]);
            }
            e[j][i] = e[i][j];
        }
    }
    for(int i=2; i<=n; ++i)
        for(int j=2; j<=i; ++j)
            for(int k=j-1; k<i; ++k)
                f[i][j] = min(f[i][j] , f[k][j-1] - eb[k]+eb[i]+e[k][i]);
    for(int i=1; i<=n; ++i){
        int ans = inf;
        for(int j=i; j<=n; ++j) {
            ans = min(ans , f[j][i]);
        }
        if(ans <= E) {
            printf("%d %d",i,ans);
            break;
        }
    }
}