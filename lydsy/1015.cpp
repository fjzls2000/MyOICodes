/**************************************************************
    Problem: 1015
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1252 ms
    Memory:12148 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 400010;
const int Maxm = 400010;
int n , m , to[Maxm] , next[Maxm] , g[Maxn] , fa[Maxn] , ecnt = 0 , ans[Maxm] , q[Maxm] , des[Maxm] , tot = 0 , d;
bool used[Maxn];
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void ins(int a , int b) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt;
}
void add(int x) {
    int p = find(x) , q;
    for(int i=g[x]; i; i=next[i])
        if(used[to[i]]) {
            q = find(to[i]);
            if(p != q) {fa[q] = p; tot--;}
        }
}
int main() {
    n = F() , m = F();
    for(int i=0; i<n; ++i) fa[i] = i;
    for(int i=1; i<=m; ++i) {
        int x = F() , y = F();
        ins(x,y);
    }
    d = F();
    for(int i=1; i<=d; ++i) {
        q[i] = F();
        des[q[i]] = 1;
    }
    for(int i=0; i<n; ++i)
        if(!des[i]) {
            ++tot;
            add(i);
            used[i] = 1;
        }
    ans[d+1] = tot;
    for(int i=d; i; --i) {
        tot++;
        add(q[i]);
        used[q[i]] = 1;
        ans[i] = tot;
    }
    for(int i=1; i<=d+1; ++i) printf("%d\n",ans[i]);
}