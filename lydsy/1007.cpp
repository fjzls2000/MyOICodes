/**************************************************************
    Problem: 1007
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:252 ms
    Memory:4812 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define eps 1e-8
 
struct line {
    double k , b; int i;
} a[100010] , s[100010];
bool cmp(line a , line b) { return fabs(a.k - b.k) < eps ? a.b < b.b : a.k < b.k;}
 
struct point { double x , y; };
double Enter(line a , line b) {
    double k1 = a.k , k2 = b.k , b1 = a.b , b2 = b.b;
    return (b2-b1)/(k1-k2);
}
 
int n , top = 0; bool ans[100010];
 
void insert(line p) {
    if(top && fabs(s[top].k - p.k) < eps) --top;
    while(top>1 && (Enter(p , s[top-1]) - Enter(s[top] , s[top-1])) <= eps ) --top;
    s[++top] = p;
}
 
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%lf%lf",&a[i].k,&a[i].b) , a[i].i = i;
    std::sort(a+1 , a+n+1 , cmp);
    for(int i=1; i<=n; ++i) insert(a[i]);
    for(int i=1; i<=top; ++i) ans[s[i].i] = 1;
    for(int i=1; i<=n; ++i) if(ans[i]) printf("%d ",i);
}