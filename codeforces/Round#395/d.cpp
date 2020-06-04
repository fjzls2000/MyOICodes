#include <stdio.h>
#include <map>
#include <algorithm>
#include <iostream>
using std::min; using std::max;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200005;
const int Maxm = 2*Maxn;
int n , rt = 0 , ans = 0 , sans = 0 , sum = 0 , fa[Maxn] , size[Maxn] , f[Maxn] , Ha[Maxn] , H[Maxn];
//fa:父亲 size：子树大小 f：最大子树大小 Ha：由trie树得到的哈希值 H:Ha出现次数
int len = 0 , a[Maxn];
int to[Maxm] , next[Maxm] , g[Maxn] , ecnt = 0;
inline void ins(const int&a , const int&b) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt;
}
namespace Trie {
    int sz = 1;
    std::map<int,int> c[Maxn];
    int insert() {
        int now = 1;
        for(int i=1; i<=len; ++i) {
            if(!c[now][a[i]]) c[now][a[i]] = ++sz;
            now = c[now][a[i]];
        } return now;
    }
}
void modify(int x , int val) {
    if(H[x]) --sum;
    H[x] += val;
    if(H[x]) ++sum;
}
void getrt(int x) {
    size[x] = 1;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        getrt(to[i]);
        size[x] += size[to[i]];
        if(size[to[i]] > f[x]) f[x] = size[to[i]];
    }
    if(n-size[x] > f[x]) f[x] = n-size[x];
    if(!rt || f[rt] > f[x]) rt = x;
}
void dfs(int x) {
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x; dfs(to[i]);
    }
    len = 0;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        a[++len] = Ha[to[i]];
    } a[++len] = 1;
    std::sort(a+1,a+len+1);
    Ha[x] = Trie::insert();
    if(x != rt) modify(Ha[x],1);
}
void getans(int x , int d) {
    if(sum+d >= sans) sans = sum+d , ans = x;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        modify(Ha[x],-1);
        getans(to[i],d+1);
        modify(Ha[x],1);
    }
}
int main() {
    n = F();
    for(int i=1; i<n; ++i) {
        int a = F() , b = F();
        ins(a,b);
    }
    getrt(1);
    fa[rt] = 0; dfs(rt);
    getans(rt,0);
    printf("%d\n",ans);
}