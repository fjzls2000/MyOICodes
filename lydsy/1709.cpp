/**************************************************************
    Problem: 1709
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1332 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
using namespace std;
 
const int Maxn = 102;
const int Max2n = 201;
int h[Maxn],l[Maxn],x1[Max2n],x2[Max2n] , map[Maxn][Maxn];
 
int main() {
    int n = F() , k = F();
    for(int i=1; i<=k; ++i) {
        int a = F() , b = F();
        ++h[a];
        ++l[b];
        ++x1[a+b-1];
        ++x2[n-b+a];
        ++map[a][b];
    }
    int ans = 0;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) {
            if((h[i] + l[j] + x1[i+j-1] + x2[n-j+i] - 3*map[i][j]) == k) {
                ++ans;
            }
        }
    printf("%d\n",ans );
}