#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200005;
int n , sum , cnt , to[Maxn]; bool vis[Maxn];
int main() {
    n = F();
    for(int i=1; i<=n; ++i) to[i] = F();
    for(int i=1; i<=n; ++i) sum += F();
    for(int i=1; i<=n; ++i)
        if(!vis[i]) {
            ++cnt;
            while(!vis[i]) vis[i] = 1 , i = to[i];
        }
    printf("%d\n",(~sum&1)+(cnt == 1 ? 0 : cnt));
}