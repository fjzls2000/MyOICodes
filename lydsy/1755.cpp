/**************************************************************
    Problem: 1755
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:820 kb
****************************************************************/
 
#include <stdio.h>
double a , b , c , ans = 1;
int main() {
    scanf("%lf%lf%lf",&a,&b,&c);
    int k = (int)c , i = 1;
    for(double tmp=(a/100)+1.0; i<=k; i<<=1 , tmp*=tmp) if(k&i) ans *= tmp;
    printf("%d",(int)(ans*b));
}