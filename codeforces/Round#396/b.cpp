#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
int n , a[Maxn];
int main() {
    n = F();
    if(n > 100) puts("YES");
    else {
        for(int i=1; i<=n; ++i) a[i] = F();
        for(int i=1; i<=n; ++i) {
            for(int j=i+1; j<=n; ++j) {
                for(int k=j+1; k<=n; ++k) {
                    if(a[i]+a[j] > a[k] && a[i]+a[k] > a[j] && a[j]+a[k] > a[i]) {
                        puts("YES"); return 0;
                    }
                }
            }
        }
        puts("NO");
    }
}