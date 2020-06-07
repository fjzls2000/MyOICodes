/**************************************************************
    Problem: 2458
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:636 ms
    Memory:4732 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define eps 1e-9
#define INF 214748364
using std::min; using std::max;
const int Maxn = 200010;
int n , tmp[Maxn];
double d;
namespace tools{ template<class T> inline T abs(T a) { return a > -eps ? a : -a; } }using namespace tools;
 
struct point {
    double x , y;
} a[Maxn] ;
point operator + (point a , point b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}
point operator - (point a , point b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
double operator * (point a , point b) { return a.x*b.y - a.y*b.x; }
double dist(point a , point b) {
    a = a - b;
    return sqrt( (a.x*a.x+a.y*a.y) );
}
bool cmpx(point a , point b) {
    return a.x == b.x ? a.y<b.y : a.x<b.x;
}
bool cmpy(int i , int j) {
    return a[i].y < a[j].y;
}
 
void Init() {
    double tx , ty , sin0 , cos0;   
    sin0 = sin(1.0);
    cos0 = cos(1.0);
    scanf("%d",&n);
    d = INF;
    for(int i=1; i<=n; i++)
        scanf("%lf%lf",&tx,&ty) , a[i].x = tx*cos0 - ty*sin0 , a[i].y = tx*sin0 + ty*cos0;
    std::sort(a+1 , a+n+1 , cmpx);
}
void Solve(int l , int r) {
    if(l + 1 >= r) return ;
     
    int tcnt = 0 , mid = (l+r+1) >> 1 ;
    Solve(l , mid) ;
    Solve(mid+1 , r);
     
    for(int i=l; i<=r; i++)
        if(abs( a[i].x - a[mid].x ) < d) tmp[++tcnt] = i;
    std::sort(tmp+1 , tmp+tcnt+1 , cmpy);
    for (int i = 1; i <= tcnt; i++)
        for (int j = i + 1; j <= tcnt && (a[tmp[j]].y - a[tmp[i]].y) - d < eps; j++)
            for (int k = j+1; k <= tcnt && (a[tmp[k]].y - a[tmp[i]].y) - d < eps; ++k)
                d = min(d , (dist(a[tmp[k]] , a[tmp[j]]) + dist(a[tmp[k]] , a[tmp[i]]) + dist(a[tmp[i]] , a[tmp[j]]))/2);
}
void End() { printf("%.6lf\n" , d*2 ); }
int main() {
    Init();
    Solve(1 , n);
    End();
}