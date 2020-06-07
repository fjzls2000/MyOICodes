/**************************************************************
    Problem: 1574
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:132 ms
    Memory:5068 kb
****************************************************************/
 
#include <stdio.h>
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10+ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
const int Maxm = 400010;
int to[Maxm] , next[Maxm] , g[Maxn] , n , m , a , b , c , ecnt = 0 , ans ; bool vis[Maxn];
void ins(int a , int b) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; }
void dfs(int x) {
    --ans; vis[x] = 1;
    for(int i=g[x]; i; i=next[i]) if(!vis[to[i]]) dfs(to[i]);
}
void del(int x) { for(int i=g[x]; i; i=next[i]) vis[to[i]] = 1; }
int main() {
    ans = n = F(); m = F(); c = F();
    while(m--) a = F() , b = F() , ins(a,b) , ins(b,a);
    while(c--) a = F() , del(a);
    dfs(1);
    printf("%d",ans);
}