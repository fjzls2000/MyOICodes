/**************************************************************
    Problem: 1583
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:720 ms
    Memory:32072 kb
****************************************************************/
 
#include <stdio.h>
#define ull unsigned long long
const int Maxn = 4000010;
ull seq[Maxn];
int c , n , a1 , a2 , b1 , b2 , c1 , c2 , p1 , p2;
int main() {
    scanf("%d%d",&c,&n);
    scanf("%d%d%d",&a1,&b1,&c1);
    scanf("%d%d%d",&a2,&b2,&c2);
    seq[1] = c;
    p1 = p2 = 1;
    ull nxt1 = seq[1]*a1/c1+b1 , nxt2 = seq[1]*a2/c2+b2;
    for(int i=2; i<=n; ) {
        if(nxt1 < nxt2) {
            if(nxt1 != seq[i-1])
                seq[i++] = nxt1;
            nxt1 = seq[++p1] * a1 / c1 + b1;
        }
        else {
            if(nxt2 != seq[i-1])
                seq[i++] = nxt2;
            nxt2 = seq[++p2] * a2 / c2 + b2;
        }
    }
    printf("%llu",seq[n]);
}