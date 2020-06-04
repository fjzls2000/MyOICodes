#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory.h>
using namespace std;
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int mod = 1000000007;
const int Maxn = 1005;
char s[Maxn];
int n , a[30] , mx = 0 , f[Maxn] , g[Maxn];
int main() {
    n = F();
    scanf("%s",s+1);
    for(int i=1; i<=26; ++i)
        a[i] = F();
    memset(g,42,sizeof(g));
    f[0] = 1; g[0] = 0;
    for(int i=1; i<=n; ++i) {
        int lim = max(0,i - a[s[i]-'a'+1]);
        for(int j=i-1; j>=lim; --j) {
            lim = max(lim , i - a[s[j]-'a'+1]);
            if(i-j > mx) mx = i-j;
            f[i] = (f[i] + f[j]) % mod;
            g[i] = min(g[i] , g[j]+1);
        }
    }
    printf("%d\n%d\n%d\n",f[n],mx,g[n]);
}