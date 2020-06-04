#include <stdio.h>
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
const int Maxm = 2*Maxn;
int n , a[Maxn] , f[Maxn][30] , fa[Maxn] , bin[30] , size[Maxn];
int to[Maxm] , next[Maxm] , g[Maxn] , ecnt = 0;
long long ans;
void ins(int a , int b) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt;  }
void dfs(int x) {
    size[x] = 1;
    for(int i=0; i<30; ++i)
        if(a[x]&bin[i]) ++f[x][i];
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        dfs(to[i]);
        for(int j=0; j<30; ++j) {
            ans += (long long)bin[j] * (f[x][j] * (size[to[i]] - f[to[i]][j]) + f[to[i]][j] * (size[x] - f[x][j]));
            if(bin[j] & a[x]) f[x][j] += size[to[i]] - f[to[i]][j];
            else f[x][j] += f[to[i]][j];
        }size[x] += size[to[i]];
    }
}
int main() {
    bin[0] = 1; for(int i=1; i<30; ++i) bin[i] = bin[i-1]<<1;
    n = F();
    for(int i=1; i<=n; ++i) a[i] = F() , ans += a[i];
    for(int i=1; i<n; ++i) {
        int p = F() , q = F();
        ins(p , q); ins(q , p);
    }
    dfs(1); printf("%I64d\n",ans);
}