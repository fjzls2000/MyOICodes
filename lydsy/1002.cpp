/**************************************************************
    Problem: 1002
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:844 kb
****************************************************************/
 
//f[i] = 3f[i-1] - f[i-2] + 2;
#include <stdio.h>
const int mod = 10000;
 
inline int max( register int a , register int b ) { return a > b ? a : b ; }
 
struct BigNum {
    int s[101];
} f[101];
 
BigNum operator - (BigNum a , BigNum b) {
    int lim = max(a.s[0] , b.s[0]); a.s[1] += 2;
    for(int i=1; i<=lim; ++i) a.s[i] = (a.s[i] < b.s[i]) ? (--a.s[i+1] , a.s[i]+mod-b.s[i]) : a.s[i]-=b.s[i];
    for(int i=1; i<=lim; ++i) a.s[i+1] += a.s[i]/mod , a.s[i] %= mod;
    if(a.s[lim+1]) ++lim;
    a.s[0] = lim;
    return a;
}
 
BigNum operator * (BigNum a , int b) {
    for(int i=1; i<=a.s[0]; ++i) a.s[i] *= b;
    for(int i=1; i<=a.s[0]; ++i) a.s[i+1] += a.s[i]/mod , a.s[i] %= mod;
    while(a.s[a.s[0]+1]) ++a.s[0]+1 , a.s[a.s[0]+1] += a.s[a.s[0]]/mod , a.s[a.s[0]] %= mod;
    return a;
}
 
void Print(BigNum a) {
    printf("%d",a.s[a.s[0]]);
    while(--a.s[0]) printf("%.4d",a.s[a.s[0]]);
} 
 
int n;
 
int main() {
    f[0].s[0] = f[1].s[0] = f[2].s[0] = f[1].s[1] = 1;
    f[2].s[1] = 5;
    scanf("%d",&n);
    for(int i=3; i<=n; ++i) f[i] = f[i-1]*3 - f[i-2];
    Print(f[n]);
}