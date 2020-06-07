/**************************************************************
    Problem: 1584
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:164 ms
    Memory:1300 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#include <math.h>
#define getch() getchar()
inline int F() {
    register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
inline int min(int a , int b) { return a > b ? b : a ; }
const int Maxn = 40005;
const int Maxm = 205;
int n , m , f[Maxn] , a[Maxn] , b[Maxm] , cnt[Maxm] , pre[Maxn] ;
int main() {
    memset(f,42,sizeof(f));
    memset(pre,-1,sizeof(pre));
    n = F(); m = F();
    int tot = 0;
    for(int i=1; i<=n; ++i) {
        int x = F();
        if(x != a[tot]) a[++tot] = x;
    }
    n = tot;
    m = sqrt(n);
    f[0] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j)
            if(pre[a[i]] <= b[j]) ++cnt[j];
        pre[a[i]] = i;
        for(int j=1; j<=m; ++j)
            if(cnt[j] > j) {
                int t = b[j]+1;
                while(pre[a[t]] > t) ++t;
                b[j] = t; --cnt[j];
            }
        for(int j=1; j<=m; ++j)
            f[i] = min(f[i] , f[b[j]]+j*j);
    }
    printf("%d",f[n]);
}