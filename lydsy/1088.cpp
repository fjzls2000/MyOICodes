/**************************************************************
    Problem: 1088
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:16 ms
    Memory:884 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 10001;
int a[Maxn] , f[Maxn] , n;
 
void Init() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
}
 
bool check() {
    int now;
    for(int i=2; i<n; i++) {
        now = f[i-1] + f[i];
        if(now > a[i] || now + 1 < a[i]) return 0;
        if(now == a[i]) f[i+1] = 0;
        else f[i+1] = 1;
    }
    if(f[n-1] + f[n] == a[n]) return 1;
    else return 0;
}
 
int main() {
    Init();
    if(a[1] == 0) {
        f[1] = f[2] = 0;
        if( check() ) puts("1");
        else puts("0");
    }
    if(a[1] == 1) {
        f[1] = 1; f[2] = 0;
        int cnt = check();
        f[1] = 0; f[2] = 1;
        cnt += check();
        printf("%d",cnt);
    }
    if(a[1] == 2) {
        f[1] = f[2] = 1;
        if( check() ) puts("1");
        else puts("0");
    }
}