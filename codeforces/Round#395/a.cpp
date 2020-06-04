#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
const int Maxm = 2*Maxn;
int n , son[Maxn] , up[Maxn] , fa[Maxn] , col[Maxn] , ans;
int to[Maxm] , next[Maxm] , g[Maxn] , ecnt = 0;
void ins(int a , int b) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; }
void dfs1(int x) {
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        dfs1(to[i]);
        if(son[x] == -1) continue;
        if(col[x] != col[to[i]] || son[to[i]]) {
            if(son[x]) son[x] = -1;
            else son[x] = to[i];
        }
    }
}
void dfs2(int x , int y) {
    int flag = 0;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        if(son[to[i]]) {
            flag = 1; break;
        }
    }
    if(!flag) { ans = x; return; }
    if(son[x] == -1 || y) return;
    if(son[x]) {
        if(col[son[x]] == col[x]) dfs2(son[x],0);
        else dfs2(son[x],1);
        return;
    }
}
int main() {
    n = F();
    for(int i=1; i<n; ++i) {
        int a = F() , b = F();
        ins(a,b); ins(b,a);
    }
    for(int i=1; i<=n; ++i) col[i] = F();
    dfs1(1); dfs2(1,0);
    if(ans) { puts("YES"); printf("%d\n",ans); }
    else puts("NO");
}