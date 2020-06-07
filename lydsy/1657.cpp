/**************************************************************
    Problem: 1657
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:84 ms
    Memory:2760 kb
****************************************************************/
 
//[Usaco2006 Mar]Mooo 奶牛的歌声
#include <stdio.h>
const int Maxn = 100010;
struct E {
    int i , h;
} q[Maxn];
int top = 0 , n , h[Maxn] , v[Maxn] , a[Maxn];
long long ans = 0;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d%d",&h[i],&v[i]);
    for(int i=1; i<=n; i++) {
        while(top && q[top].h <= h[i]) top--;
        if(top) a[q[top].i] += v[i];
        q[++top].h = h[i]; q[top].i = i;
    }top = 0;
    for(int i=n; i; i--) {
        while(top && q[top].h <= h[i]) top--;
        if(top) a[q[top].i] += v[i];
        q[++top].h = h[i]; q[top].i = i;
    }
    while( n ) {
        if(a[n] > ans) ans = a[n];
        n--;
    }printf("%lld",ans);
}