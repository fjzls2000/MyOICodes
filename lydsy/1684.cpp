/**************************************************************
    Problem: 1684
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:820 kb
****************************************************************/
 
#include <stdio.h>
#include <math.h>
int main() {
    int n , m , ansx = 0 , ansy = 0;
    scanf("%d%d",&n,&m);
    double t = n , ans = 233333333 ;
    t /= m;
    for(int i=1; i<=32767; ++i) {
        int x , y = i;
        x = t*y;
        double t1 = x; t1 /= y;
        if(x * m != y * n) if(fabs(t1 - t) < ans) {ans = fabs(t1 - t); ansx = x; ansy = y;}
        ++x;
        if(x * m == y * n) continue;
        t1 = x; t1 /= y;
        if(fabs(t1 - t) < ans) {ans = fabs(t1 - t); ansx = x; ansy = y;}
    }
    printf("%d %d",ansx , ansy);
}