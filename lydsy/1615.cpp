/**************************************************************
    Problem: 1615
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:852 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 1110;
struct node { int x , y , r; } c[Maxn];
double v[Maxn] , ans = 0;
int n , ax , ay , first , last , h , t , q[Maxn] , fa[Maxn];
bool vis[Maxn];
inline int sqr(int x) { return x * x; }
inline int dis(int x , int y) { return sqr(c[x].x-c[y].x)+sqr(c[x].y-c[y].y); }
inline bool qie(int x , int y) { return sqr(c[x].r+c[y].r) == dis(x,y); }
int main() {
    n = F() , ax = F() , ay = F();
    for(int i=1; i<=n; ++i)
        c[i].x = F() , c[i].y = F() , c[i].r = F();
    for(int i=1; i<=n; ++i) {
        if(!c[i].x && !c[i].y) first = i;
        if(c[i].x == ax && c[i].y == ay) last = i;
    }
    v[ q[h = t = 1] = first ] = 10000; vis[first] = 1;
    while(h <= t) {
        int now = q[h++];
        for(int i=1; i<=n; ++i) {
            if(vis[i]) continue;
            if(qie(now,i)) {
                vis[i] = 1; fa[i] = now; q[++t] = i;
                v[i] = v[now]*c[now].r/c[i].r;
                if(i == last) {
                    h = t+1;
                    break;
                }
            }
        }
    }
    for(int i=last; i; i=fa[i])
        ans += v[i];
    printf("%d\n",(int)ans);
}