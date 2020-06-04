/**************************************************************
    Problem: 3631
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:852 ms
    Memory:20996 kb
****************************************************************/
 
#include <stdio.h>
inline void swap(int&a , int&b) { register int c = a; a=b; b = c; }
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 300010;
const int Maxm = Maxn<<1;
int n , a[Maxn] , size[Maxn] , son[Maxn] , dep[Maxn] , s[Maxn] , fa[Maxn] , bl[Maxn] , pl[Maxn] , dfn = 0 , to[Maxm] , next[Maxm] , g[Maxn] , ecnt = 0;
inline void ins(const int&a , const int&b) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt;
}
void dfs1(int x) {
    size[x] = 1; dep[x] = dep[fa[x]] + 1;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        dfs1(to[i]);
        size[x] += size[to[i]];
        if(size[to[i]] > size[son[x]]) son[x] = to[i];
    }
}
void dfs2(int x , int y) {
    bl[x] = y; pl[x] = ++dfn;
    if(!son[x]) return;
    dfs2(son[x] , y);
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x] || to[i] == son[x]) continue;
        dfs2(to[i],to[i]);
    }
}
int lca(int x , int y) {
    while(bl[x] != bl[y]) {
        if(dep[fa[bl[x]]] < dep[fa[bl[y]]]) swap(x,y);
        x = fa[bl[x]];
    }return dep[x] <= dep[y] ? x : y ;
}
void dfs(int x) {
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        dfs(to[i]);
        s[x] += s[to[i]];
    }
}
int main() {
    n = F();
    for(int i=1; i<=n; ++i)
        a[i] = F();
    for(int i=1; i<n; ++i)
        ins(F(),F());
    dfs1(1);
    dfs2(1,1);
    for(int i=1; i<n; ++i) {
        ++s[a[i]]; ++s[a[i+1]];
        int tmp = lca(a[i],a[i+1]);
        --s[tmp]; --s[fa[tmp]];
    }
    dfs(1);
    for(int i=2; i<=n; ++i) --s[a[i]];
    for(int i=1; i<=n; ++i)
        printf("%d\n",s[i] );
}