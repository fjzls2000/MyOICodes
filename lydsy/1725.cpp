/**************************************************************
    Problem: 1725
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:1736 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define inf 2147483647
using namespace std;
const int mod = 100000000;
const int Maxn = 1<<13;
int n , m , f[14][Maxn] , ans , mp[14] , ed;
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int main() {
    n = F(); m = F();
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            int tmp = F();
            mp[i]<<=1; mp[i]+=tmp;
    }
    ed = (1<<m)-1;
    for(int i=0; i<=ed; ++i) {
        if((i & (i>>1)) == 0 && (i | mp[1]) == mp[1])
            f[1][i] = 1;
    }
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<=ed; ++j) {
            if(f[i-1][j]) {
                for(int k=0; k<=ed; ++k) {
                    if(((j&k) == 0) && ((k|mp[i]) == mp[i]) && ((k & (k>>1)) == 0))
                        f[i][k] = (f[i][k] + f[i-1][j]) % mod;
                }
            }
        }
    }
    for(int i=0; i<=ed; ++i) {
        ans = (ans + f[n][i]) % mod;
    }
    printf("%d\n", ans);
}