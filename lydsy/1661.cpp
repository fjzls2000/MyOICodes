/**************************************************************
    Problem: 1661
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1768 ms
    Memory:1332 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
 
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 105;
int n , mp[Maxn][Maxn] , ch , ans = 0;
 
void solve(int x1 , int y1 , int x2 , int y2) {
    int tx=x2-x1 , ty=y2-y1;
    if(ty>=x1 || y2+tx>n)return;
    if(mp[x2-ty][y2+tx] == 0)return;
    if(mp[x1-ty][y1+tx] == 0)return;
    int t = mp[x2-ty][y2+tx] + mp[x1-ty][y1+tx] + mp[x1][y1] + mp[x2][y2];
    if(t>=7)
        ans=max(ans,tx*tx+ty*ty);
}
int main() {
    n=F();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            while(ch = getchar() , ch!='J' && ch != '*' && ch != 'B');
            if(ch == 'J') mp[i][j]=2;
            if(ch == '*') mp[i][j]=1;
        }
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            if(mp[x][y])
                for(int i=x;i<=n;i++)
                    for(int j=y;j<=n;j++)
                        if(mp[i][j] && (x!=i || y!=j))
                            solve(x,y,i,j);
    printf("%d\n",ans);
    return 0;
}