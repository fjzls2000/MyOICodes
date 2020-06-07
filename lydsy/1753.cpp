/**************************************************************
    Problem: 1753
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:24 ms
    Memory:4728 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
int a[1000010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    std::sort(a+1,a+n+1);
    printf("%d",a[(n+1)>>1]);
}