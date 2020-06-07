/**************************************************************
    Problem: 3715
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8912 ms
    Memory:2972 kb
****************************************************************/
 
#include <stdio.h>
#include <memory.h>
#include <algorithm>
struct node { int a , b , c , d , i; } a[100010];
bool cmp1(node a , node b) { return a.a < b.a; }
bool cmp2(node a , node b) { return a.b > b.b; }
bool cmp3(node a , node b) { return a.c < b.c; }
bool cmp4(node a , node b) { return a.d > b.d; }
short int tong[100010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        memset(tong , 0 , sizeof(tong));
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)
            scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d) , a[i].i = i;
        std::sort(a+1,a+n+1,cmp1);
        for(int i=1; a[i].a == a[1].a && i<=n; ++i) ++tong[a[i].i];
        std::sort(a+1,a+n+1,cmp2);
        for(int i=1; a[i].b == a[1].b && i<=n; ++i) ++tong[a[i].i];
        std::sort(a+1,a+n+1,cmp3);
        for(int i=1; a[i].c == a[1].c && i<=n; ++i) ++tong[a[i].i];
        std::sort(a+1,a+n+1,cmp4);
        for(int i=1; a[i].d == a[1].d && i<=n; ++i) ++tong[a[i].i];
        for(int i=1; i<=n; ++i) if(tong[i] == 4) {
            puts("TAK");
            n = -1;
            break;
        }if(n != -1)puts("NIE");
    }
}