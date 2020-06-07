/**************************************************************
    Problem: 1591
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1444 ms
    Memory:1864 kb
****************************************************************/
 
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define inf 233333333
 
inline int max(int a , int b) { return a > b ? a : b ; }
 
const int Maxn = 256;
struct P{
    double x , y;
    P(){} P(double _x , double _y) { x = _x; y = _y; }
} p[Maxn];
struct line {
    int u , v; double a;
} l[Maxn*Maxn];
 
bool cmp(line a , line b) {
    return a.a < b.a;
}
 
int f[Maxn] , n , cnt = 0 , ans = 0;
 
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if(i != j) {
                l[++cnt].u = i;
                l[cnt].v = j;
                l[cnt].a = atan2(p[j].y-p[i].y , p[j].x-p[i].x);
            }
    std::sort(l+1,l+cnt+1,cmp);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j)
            f[j] = -inf;
        f[i] = 0;
        for(int j=1; j<=cnt; ++j) {
            f[l[j].v] = max(f[l[j].v] , f[l[j].u]+1);
        }
        ans = max(ans , f[i]);
    }
    printf("%d",ans);
}