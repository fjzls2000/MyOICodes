/**************************************************************
    Problem: 1349
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:828 kb
****************************************************************/
 
#include <stdio.h>
#include <math.h>
int main() {
    long long ans , a;
    scanf("%lld",&ans);
    a = sqrt(ans);
    if(a * a != ans) ++a;
    printf("%lld",a); 
}