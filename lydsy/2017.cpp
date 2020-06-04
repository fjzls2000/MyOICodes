/**************************************************************
    Problem: 2017
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:204 ms
    Memory:16476 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <queue>
#define inf 233333333
using namespace std;
 
inline int F() {
    register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 2001;
#define R register
int n , a[Maxn] , s[Maxn] , f[Maxn][Maxn];
 
int main() {
    n = F();
    for(int i=n; i; --i) a[i] = F();
    for(int i=1; i<=n; ++i) s[i] = s[i-1] + a[i]; 
    for(int i=1; i<=n; ++i) {
        int mn = inf;
        for(int j=1; j<=n; ++j) {
            int t = j+j;
            if(t <= i) mn = min(mn , f[i-t][t]);
            --t;
            if(t <= i) mn = min(mn , f[i-t][t]);
            f[i][j] = s[i] - mn;
        }
    }printf("%d",f[n][1]);
}