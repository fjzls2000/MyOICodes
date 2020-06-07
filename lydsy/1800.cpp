/**************************************************************
    Problem: 1800
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:824 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 21;
int s[Maxn] , dis[Maxn][Maxn] , ans = 0;
int main() {
    int n = F();
    for(int i=1; i<=n; ++i) s[i] = s[i-1] + F();
    for(int i=1; i<=n; ++i)
    for(int j=i+1; j<=n; ++j)
    for(int a=j+1; a<n; ++a)
    for(int b=a+1; b<=n; ++b)
    if(s[j-1]-s[i-1] == s[b-1]-s[a-1] && s[i-1]+s[n]-s[b-1]==s[a-1]-s[j-1]) ++ans;
    printf("%d",ans);
}