/**************************************************************
    Problem: 1580
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:328 ms
    Memory:2396 kb
****************************************************************/
 
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long
int n , r , bx , by , bvx , bvy , x , y , vx , vy , i , m , t , ans;
double L , R , inf = 1e9;
const int Maxn = 100010;
inline int max(int a , int b) {return a > b ? a : b ;}
struct P{
    double x , y;
    P(){}
    P(double _x,double _y) {x = _x; y = _y;}
} a[Maxn] ;
  
inline bool cmp(P a , P b) { return a.x < b.x; }
// (x+tvx)^2 + (y+tvy)^2 = r^2
inline void getlr (ll a , ll b , ll c) {
    if(!a) {
        if(c <= 0) L = 0 , R = inf;
        else L = R = -inf;
        return;
    }
    ll d = b*b-a*c*4;
    if(d < 0) {
        L = R = -inf;
        return;
    } 
    L = (-1.0*b-sqrt(d))/2/a;
    R = (-1.0*b+sqrt(d))/2/a;
    if(R < 0) L = R = -inf;
    if(L < 0) L = 0;
}
  
int main() {
    scanf("%d%d%d%d%d%d",&n,&r,&bx,&by,&bvx,&bvy);
    while(n--) {
        scanf("%d%d%d%d",&x,&y,&vx,&vy);
        x -= bx; y -= by; vx -= bvx; vy -= bvy;
        getlr(vx*vx+vy*vy,2*(x*vx+y*vy),x*x+y*y-r*r);
        if(R >= -1) a[++m] = P(L,1),a[++m] = P(R,-1);
    }
    std::sort(a+1,a+m+1,cmp);
    for(int i=1; i<=m; ++i)
        ans = max(ans , t+=a[i].y);
    printf("%d",ans);
}