/**************************************************************
    Problem: 1660
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:92 ms
    Memory:1588 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 100010;
int a[Maxn] , q[Maxn] , top = 0 , n , tmp;
long long ans = 0;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&tmp);
        while(top && q[top] <= tmp) top--;
        ans += top;
        q[++top] = tmp;
    }printf("%lld",ans);
}