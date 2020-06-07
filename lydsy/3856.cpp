/**************************************************************
    Problem: 3856
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:820 kb
****************************************************************/
 
#include <stdio.h>
int main() {
    long long a,b,c,d , aa , bb , cnt = 0;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d) != EOF) {
        if(a == 0 && b == 0 && c == 0 && d == 0) return 0;
        if(a<=b) {printf("Case #%d: YES\n",++cnt); continue;}
        aa = c-b; aa *= d; aa-=c;
        if(aa+a <= 0) {printf("Case #%d: YES\n",++cnt); continue;}
        if(aa+c+c < 0) {printf("Case #%d: YES\n",++cnt); continue;}
        printf("Case #%d: NO\n",++cnt);
    }
} 