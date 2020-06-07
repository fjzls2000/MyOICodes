/**************************************************************
    Problem: 2822
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:812 kb
****************************************************************/
 
#include <stdio.h>
const int mod = 10000;
int a[1500];
inline void MUL(register int x) {
    for(register int i=1; i<=a[0]; i++) a[i] *= x;
    for(register int i=1; i<=a[0]; i++) if( a[i] > mod ) { a[i+1] += a[i]/mod ; a[i] %= mod;}
    if(a[a[0]+1]) a[0]++;
}
inline void div(register int x) {
    for(register int i=a[0]; i>1; i--) {
        a[i-1] += (a[i] % x) * mod;
        a[i] /= x;
    }a[1] /= x;
    while(a[a[0]] == 0) a[0]--;
}
void Print() {
    register int k = a[0];
    printf("%d",a[k]);
    while(--k) printf("%.4d",a[k]);
}
int main() {
    register int n;
    scanf("%d",&n);
    a[1] = (n+2) % mod;  a[2] = (n+2) / mod;
    if(a[2]) a[0] = 2 ;  else a[0] = 1;
    for(register int i=3; i<=n; i++) MUL(i+n) , div(i-1);
    div(n);  Print();
    return 0;
}