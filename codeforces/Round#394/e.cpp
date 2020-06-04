#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 31;
const int Maxm = 60;
const long long inf = 1e18;
const int sx[4] = {1,-1,0,0};
const int sy[4] = {0,0,1,-1};
int n , to[Maxm] , next[Maxm] , g[Maxn] , du[Maxn] , ecnt = 0;
long long  x[Maxn] , y[Maxn]; bool vis[Maxn];
inline void ins(int a , int b) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; ++du[b]; }
void dfs(int now , int lst , long long len) {
    vis[now] = 1;
    for(int i=0; i<4; ++i) {
        if(i == (lst^1)) continue;
        for(int j=g[now]; j; j=next[j]) {
            if(!vis[to[j]]) {
                x[to[j]] = x[now] + sx[i]*len;
                y[to[j]] = y[now] + sy[i]*len;
                dfs(to[j],i,len/2);
                break;
            }
        }
    }
}
int main() {
    n = F();
    for(int i=1; i<n; ++i) {
        int a = F() , b = F();
        ins(a,b); ins(b,a);
    }
    for(int i=1; i<=n; ++i) {
        if(du[i] > 4) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    x[1] = inf/2; y[1] = inf/2;
    dfs(1,5,inf/4);
    for(int i=1; i<=n; ++i) {
        printf("%I64d %I64d\n",x[i],y[i]);
    }
}