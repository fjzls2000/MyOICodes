/**************************************************************
    Problem: 1192
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:804 kb
****************************************************************/
 
#include <stdio.h>
int main() {
    long long m , ans = 0;
    scanf("%lld",&m);
    while(m) {ans++;m>>=1;}
    printf("%lld",ans);
}