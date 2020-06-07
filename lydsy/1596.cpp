/**************************************************************
    Problem: 1596
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:2384 kb
****************************************************************/
 
#include <stdio.h>
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
int n , to[Maxn] , next[Maxn] , g[Maxn] , mark[Maxn] , ans = 0 , ecnt = 0;
inline void ins(int a , int b) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt;
}
void dfs(int x , int fa){
    bool flag = 0;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa) continue;
        dfs(to[i],x);
        if(mark[to[i]]) flag = 1;
    }
    if(!flag && !mark[x] && !mark[fa]) { ++ans; mark[fa]=1; }
}
int main() {
    n = F();
    for(int i=1; i<n; ++i) {
        int u = F() , v = F();
        ins(u,v),ins(v,u);
    }
    dfs(1,0);
    printf("%d",ans);
}