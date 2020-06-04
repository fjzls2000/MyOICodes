/**************************************************************
    Problem: 1101
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:6196 ms
    Memory:1456 kb
****************************************************************/
 
#include <stdio.h>
inline int F() {
    register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 50001;
int mu[Maxn] , p[Maxn] , top = 0 , s[Maxn]; bool vis[Maxn];
inline int min(const int&a , const int&b) { return a < b ? a : b ; }
void init() {
    mu[1]=1;
    for(int i=2; i<=50000; ++i) {
        if(!vis[i]) { mu[i]=-1; p[++top]=i; }
        for(int j=1; j<=top && i*p[j]<=50000; ++j) {
            vis[i*p[j]] = 1;
            if(i % p[j]==0) { mu[i*p[j]]=0; break; }
            else mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=50000;i++)
        s[i]=s[i-1]+mu[i];
}
int cal(int a , int b) {
    if(a > b) return cal(b,a);
    int ans = 0 , pos;
    for(int i=1; i<=a; i = pos+1) {
        pos = min( (a/(a/i)) , (b/(b/i)) );
        ans += (s[pos] - s[i-1]) * (a/i) * (b/i);
    }return ans;
}
int main() {
    init();
    int t = F();
    while(t--) {
        int a = F() , b = F() , k = F();
        a/=k; b/=k;
        printf("%d\n",cal(a,b));
    }
}