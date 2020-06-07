/**************************************************************
    Problem: 1355
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:28 ms
    Memory:5688 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 1000010;
char s[Maxn]; int fail[Maxn] , j , n;
int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    fail[0] = -1;
    for(int i=1; i<=n; i++) {
        for(j = fail[i-1]; j!=-1 && s[j+1] != s[i]; j=fail[j]);
        fail[i] = ++j;
    }if(fail[n] == -1) fail[n] = 0;
    printf("%d",n-fail[n]);
}