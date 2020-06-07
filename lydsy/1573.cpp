/**************************************************************
    Problem: 1573
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:236 ms
    Memory:5600 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int Maxn = 100010;
const int Max2n = 200010;
long long ans = 0;
double d;
int n , cnt = 0 , vis[Maxn];
struct point {
    double ang;
    int i;
} p[Max2n];
bool cmp (point a , point b) {
    return a.ang > b.ang;
}
point Point(double a , int b) {
    point tmp;
    tmp.ang = a;
    tmp.i = b;
    return tmp;
}
 
#define lowbit(a) ((a) & -(a))
 
long long tree[Max2n];
 
int query(int x) {
    int ret = 0;
    while(x) {
        ret += tree[x];
        x -= lowbit(x);
    }
    return ret;
}
void update(int x , int k) {
    while(x <= cnt) {
        tree[x] += k;
        x += lowbit(x);
    }
}
 
int main() {
    scanf("%d%lf",&n,&d);
    for(int i=1; i<=n; ++i) {
        double a , b , c;
        scanf("%lf%lf%lf",&a,&b,&c);
        if(c*c <= d*d * (a*a + b*b)) {
            if(b != 0) {
                double A = (1 + a*a/b/b);
                double B = -(2*a*c/b/b);
                double C = c*c/b/b-d*d;
                double x1 = (-B+sqrt(B*B-4*A*C))/2/A;
                double x2 = (-B-sqrt(B*B-4*A*C))/2/A;
                double y1 = (a*x1-c)/b;
                double y2 = (a*x2-c)/b;
                p[++cnt] = Point(atan2(y1,x1) , i);
                p[++cnt] = Point(atan2(y2,x2) , i);
            }
            else {
                double x = -c/a;
                double y1 = sqrt(d*d-x*x);
                double y2 = -y1;
                p[++cnt] = Point(atan2(y1,x) , i);
                p[++cnt] = Point(atan2(y2,x) , i);
            }
        }
    }
    sort(p+1 , p+cnt+1 , cmp);
    for(int i=1; i<=cnt; ++i) {
        if(vis[p[i].i]) {
            ans += query(i) - query(vis[p[i].i]);
            update(vis[p[i].i] , -1);
        }
        else {
            vis[p[i].i] = i;
            update(i,1);
        }
    }
    cout<<ans;
}