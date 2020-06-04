/**************************************************************
    Problem: 1647
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:236 ms
    Memory:824 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define inf 233333333
inline long long min(register long long a , register long long b) { return a < b ? a : b ; }
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
#define ll long long
const int Maxn = 16;
int n , m , a[Maxn][Maxn] , ed , mn = inf , ans[Maxn][Maxn] , op[Maxn][Maxn] , t[Maxn][Maxn];
const int sx[4] = {1,0,-1,0}; const int sy[4] = {0,1,0,-1};
bool operate(int x , int y) {
    ++op[x][y]; t[x][y] ^= 1;
    for(int i=0; i<4; ++i) {
        int nx = x+sx[i] , ny = y+sy[i];
        if(nx<1 || ny<1 || nx>n || ny>m)continue;
        t[nx][ny] ^= 1;
    }
}
void Solve(int x) {
    memset(op,0,sizeof(op));
    int tot = 0;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            t[i][j] = a[i][j];
    for(int i=1; i<=m; ++i)
        if((1<<(i-1))&x) {
            ++tot;
            if(tot >= mn) return;
            operate(1,m-i+1);
        }
    for(int i=2; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(t[i-1][j]) {
                ++tot;
                if(tot>=mn) return;
                operate(i,j);
            }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(t[i][j]) return;
    mn = tot;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            ans[i][j] = op[i][j];
}
int main() {
    n = F(); m = F();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
            a[i][j] = F();
    ed=(1<<m)-1;
    for(int i=0; i<=ed; i++) Solve(i);
    if(mn!=inf)
        for(int i=1; i<=n; printf("%d\n",ans[i][m]),i++)
        for(int j=1; j<m; j++) printf("%d " , ans[i][j]);
    else puts("IMPOSSIBLE");
}