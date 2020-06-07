/**************************************************************
    Problem: 1385
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:172 ms
    Memory:1212 kb
****************************************************************/
 
#include <stdio.h>
inline int gcd(int a , int b) { return b ? gcd(b,a%b) : a ; }
int t , T , n , a[100010];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&a[1],&t);
        for(int i=2; i<n; ++i)
            scanf("%d",&a[i]);
        for(int i=1; i<n; ++i) {
            t /= gcd(t,a[i]);
            if(t == 1) {
                puts("YES");
                break;
            }
        }
        if(t != 1) puts("NO");
    }
}