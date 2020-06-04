#include <stdio.h>
#include <iostream>
using std::swap;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch!='-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200005;
int n , a[Maxn];
int main() {
    int n = F();
    for(int i=1; i<=n; ++i) a[i] = F();
    for(int i=1; i+i<=n; ++i) if(i&1) swap(a[i],a[n-i+1]);
    for(int i=1; i<=n; ++i) printf("%d ",a[i]);
}