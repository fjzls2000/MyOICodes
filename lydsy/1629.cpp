/**************************************************************
    Problem: 1629
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:76 ms
    Memory:1604 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
inline int max(int a , int b) {return a > b ? a : b ;}
const int Maxn = 100010;
struct node {
    int a , b;
} a[Maxn];
bool cmp(node a , node b) {
    return a.a-b.b < b.a-a.b;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d%d",&a[i].a,&a[i].b);
    std::sort(a+1,a+n+1,cmp);
    int ans = -233333333 , tot = 0;
    for(int i=1; i<=n; ++i) {
        ans = max(ans , tot-a[i].b);
        tot += a[i].a;
    }printf("%d",ans);
}